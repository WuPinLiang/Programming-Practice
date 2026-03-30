#include <iostream>
#include <vector>
#define N 200005
#define int long long
using namespace std;

vector<int> adj[N];
vector<int> dist(N, 0);

inline void dfs(int u, int pa) {
    dist[u] = dist[pa] + 1;
    for(int v : adj[u]) {
        if(v == pa) continue ;
        dfs(v, u);
    }
    return ;
}

inline void solve() {
    int n;cin >> n;
    for(int i = 0;i < n-1;i++) {
        int a, b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, 0);
    
    int target = -1, max_dist = -1;
    for(int i = 0;i < n;i++) {
       if(dist[i] > max_dist) {
          max_dist = dist[i];
          target = i;
       } 
    }
  
    dist.assign(N, 0);
    dfs(target, target);

    int ans = -1;
    for(int i = 0;i < n;i++) {
        ans = max(ans, dist[i]);
    }
    cout << ans - 1 << '\n';
    return ;
}

signed main() {
    solve();
    return 0;
}
