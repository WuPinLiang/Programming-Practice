#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector")
#include <iostream>
#include <vector>
#include <queue>
#define int long long 
#define N 500005

using namespace std;
const int inf = 1e18;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> deg(n + 1, 0);
    vector<int> adj[n + 1];
    for(int i = 1;i <= m;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }
    queue<int> q;
    vector<int> ans;
    for(int i = 1;i <= n;i++)
        if(deg[i] == 0)
            q.push(i);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(int nxt : adj[cur]) {
            if(--deg[nxt] == 0)
                q.push(nxt);
        }
    }
    if(ans.size() != n) {
        cout << "IMPOSSIBLE\n";
        return ;
    }
    for(int num : ans)
        cout << num << ' ';
    cout << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}