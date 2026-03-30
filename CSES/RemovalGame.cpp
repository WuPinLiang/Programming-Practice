#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#define int long long 
#define N 500005

using namespace std;
const int inf = 1e18;

inline void solve() {
    int n;cin >> n;
    vector<int> v(n + 1), psum(n + 1, 0);
    for(int i = 1;i <= n;i++) {
        cin >> v[i];
        psum[i] = psum[i-1] + v[i];
    }
    vector<vector<int> > dp(n + 1, vector<int> (n + 1, 0));
    for(int i = 1;i <= n;i++)
        dp[i][i] = v[i];
    
    for(int len = 2;len <= n;len++) {
        for(int i = 1;i + len - 1 <= n;i++) {
            int j = i + len - 1;
            dp[i][j] = psum[j] - psum[i-1] - min(dp[i + 1][j], dp[i][j-1]);
        }
    }
    cout << dp[1][n] << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}