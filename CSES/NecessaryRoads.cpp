#include <iostream>
#include <vector>
#define int long long
#define N 100005
#define inf 1e18

using namespace std;
using pii = pair<int, int> ;

int n, m;

// low 紀錄最高可以到多高，數字越小表示越高

vector<pii> bridge;
vector<int> adj[N];
vector<int> dfn(N, 0), low(N, inf);
int ord = 1;

inline void dfs(int cur, int pa = -1) {

    dfn[cur] = low[cur] = ord++;
    
    for(int nxt : adj[cur]) {
        if(!dfn[nxt]) {
            dfs(nxt, cur);
            low[cur] = min(low[cur], low[nxt]); // 計算以 cur 為根的子樹可達到的最高高度
            if(low[nxt] > dfn[cur]) {
                bridge.push_back({cur, nxt});
            }
        }else if(nxt != pa) {
            low[cur] = min(low[cur], dfn[nxt]);
        }
    }
}

inline void solve() {
    cin >> n >> m;
    for(int i = 0;i < m;i++) {
        int a, b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1;i <= n;i++) {
        if(!dfn[i]) {
            dfs(i);
        }
    }
    cout << bridge.size() << '\n';
    for(auto [a, b] : bridge) {
        cout << a << ' ' << b << '\n';
    }
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
