#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector")
#include <iostream>
#include <vector>
#include <queue>
#define int long long 
#define N 500005

using namespace std;
using pii = pair<int, int>;
const int inf = 1e18;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> adj[n + 1];
    vector<int> dist(n + 1, inf);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(int i = 1;i <= m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();
        if(cur_dist > dist[cur])
            continue ;
        for(auto [nxt_dist, nxt] : adj[cur]) {
            if(dist[cur] + nxt_dist < dist[nxt]) {
                dist[nxt] = dist[cur] + nxt_dist;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    for(int i = 1;i <= n;i++)
        cout << dist[i] << ' ';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}