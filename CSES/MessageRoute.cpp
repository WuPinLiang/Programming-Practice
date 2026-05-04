#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define int long long

using namespace std;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n + 1, 0), dis(n + 1, 1e9 + 7), pa(n + 1, -1);
    vis[1] = 1, dis[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int nxt : adj[cur]) {
            if(!vis[nxt]) {
                vis[nxt] = 1;
                q.push(nxt);
                if(dis[cur] + 1 < dis[nxt]) {
                    dis[nxt] = dis[cur] + 1;
                    pa[nxt] = cur;
                }
            }
        }
    }
    if(!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return ;
    }
    vector<int> ans;
    for(int i = n;i != -1;i = pa[i]) {
        ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int i : ans)
        cout << i << ' ';
    cout << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}