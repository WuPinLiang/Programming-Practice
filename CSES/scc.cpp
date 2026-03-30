#include <iostream>
#include <vector>
#define int long long
#define N (int)1e5 + 5

using namespace std ;

int n, m;
vector<int> adj[N], revadj[N], scc_id(N, 0), pos, vis(N, 0), v(N);

inline void revdfs(int cur) {
    //cerr << "1 " << cur << "\n";
    vis[cur] = 1;
    for(int nxt : revadj[cur]) {
        if(vis[nxt])  continue; 
        revdfs(nxt);
    }
    pos.push_back(cur);
    return ;
}

inline void dfs(int cur, int val) {
    //cerr << "2 " << cur << " " << val << "\n";
    scc_id[cur] = val;
    for(int nxt : adj[cur]) {
        if(scc_id[nxt] == 0)  dfs(nxt, val);
    }
}

inline void add_edge(int a, int b) {
    adj[a].push_back(b);
    revadj[b].push_back(a);
    return ;
}

inline void kosaraju() {
    for(int i = 1;i <= n;i++) {
        if(!vis[i])   revdfs(i);
    }
    
    int cnt = 0; // count the number of this SCC

    for(int i = n-1;i >= 0;i--) {
        int tmp = pos[i];
        if(!scc_id[tmp]) {
            dfs(tmp , ++cnt);
        }
    }
    
    cout << cnt << '\n';
    for(int i = 1;i <= n;i++)
        cout << scc_id[i] << ' ';
    cout << '\n';
}

inline void solve() {
    cin >> n >> m;

    for(int i = 1;i <= n;i++) 
        cin >> v[i];

    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;

        add_edge(a, b);
    }
    
    kosaraju();

    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
