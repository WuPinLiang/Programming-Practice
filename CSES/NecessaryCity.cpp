#include <iostream>
#include <vector>
#define int long long
#define N 100005
#define inf 1e18
 
using namespace std;
using pii = pair<int, int> ;
 
int n, m;

vector<int> cut(N, 0);
vector<int> adj[N];
vector<int> dfn(N, 0), low(N, inf);
int ord = 1;

inline void dfs(int cur, int pa = -1) {
    int child_cnt = 0;
    dfn[cur] = low[cur] = ord++;
    for(int nxt : adj[cur]) {
        if(!dfn[nxt]) {
            child_cnt ++;
            dfs(nxt, cur);
            low[cur] = min(low[cur], low[nxt]); // 維護 low 可以想像成 dp 
            if(low[nxt] >= dfn[cur])
                cut[cur] = 1;
        }else if(nxt != pa) {
            low[cur] = min(low[cur], dfn[nxt]);
        }
    }
    if(child_cnt == 1 and dfn[cur] == 1) 
        cut[cur] = 0;
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
    vector<int> ans;
    for(int i = 0;i <= n;i++) 
        if(cut[i])
            ans.push_back(i);
    cout << ans.size() << '\n';
    for(int a : ans)
        cout << a << ' ';
    cout << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
