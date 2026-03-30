#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector")
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define int long long 
#define N 500005

using namespace std;
const int inf = 1e18;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1], deg(n + 1, 0);
    for(int i = 1;i <= m;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }
    queue<int> q;
    for(int i = 1;i <= n;i++) 
        if(deg[i] == 0)
            q.push(i);
    vector<int> dp(n + 1, -inf), pa(n + 1, -1);
    dp[1] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int nxt : adj[cur]) {
            if(dp[cur] != -inf and dp[cur] + 1 > dp[nxt]) {
                dp[nxt] = dp[cur] + 1;
                pa[nxt] = cur;
            }
            if(--deg[nxt] == 0)
                q.push(nxt);
        }
    }

    if(dp[n] <= -inf) {
        cout << "IMPOSSIBLE\n";
        return ;
    }
    cout << dp[n] + 1 << '\n';
    int cur = n;
    vector<int> ans;
    while(cur != -1) {
        ans.push_back(cur);
        cur = pa[cur];
    }
    reverse(ans.begin(), ans.end());
    for(int x : ans)
        cout << x << ' ';
    cout << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}