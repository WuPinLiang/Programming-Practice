#pragma GCC optimize("Ofast, unroll-loops, no-stack-protescor, fast-math")
#include <iostream>
#include <vector>
#define int long long 
#define lowbit(x) (x &(-x))
#define N 200005

using namespace std ;

vector<int> v(N), tin(N), tout(N);
vector<int> adj[N];
int bit[N];
int n, q, timer = 0;

inline int query(int idx) {
    int sum = 0;
    for(int i = idx;i > 0;i -= lowbit(i)) {
        sum += bit[i];
    }
    return sum;
}

inline void update(int idx, int val) {
    for(int i = idx;i < N;i += lowbit(i)) {
        bit[i] += val;
    }
    return void();
}

inline void dfs(int cur, int pa) {
    tin[cur] = ++timer;
    for(int nxt : adj[cur]) {
        if(nxt == pa)
            continue ;
        dfs(nxt, cur);
    }
    tout[cur] = timer;// we don't need to '++' here 
    return ;
}

inline void solve() {
    cin >> n >> q;
    for(int i = 1;i <= n;i++)   cin >> v[i];

    for(int i = 1;i < n;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    for(int i = 1;i <= n;i++)
        update(tin[i], v[i]);
    
    for(int i = 0;i < q;i++) {
        int opt;cin >> opt;
        if(opt == 1) {
            int node, num;cin >> node >> num;
            int d = num - v[node];
            v[node] = num;
            update(tin[node], d);
        }else {
            int node;cin >> node;
            cout << query(tout[node]) - query(tin[node] - 1) << '\n';
        }
    }
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
