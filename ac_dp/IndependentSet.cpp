#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#include <iostream>
#include <vector>
#define int long long 
#define N 100005
#define mod 1000000007

using namespace std;

int n, root;
vector<int> adj[N];
int dp[N][2];

void dfs(int cur, int par) {
    dp[cur][0] = dp[cur][1] = 1;
    for (int nxt : adj[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
        dp[cur][0] = (dp[cur][0] * ((dp[nxt][0] + dp[nxt][1]) % mod)) % mod;
        dp[cur][1] = (dp[cur][1] * dp[nxt][0]) % mod;
    }
}

void solve() {
    cin >> n;
    vector<bool> is_root(n + 1, 1); 
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        is_root[b] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (is_root[i]) root = i;
    }
    dfs(root, -1);
    cout << (dp[root][0] + dp[root][1]) % mod << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
