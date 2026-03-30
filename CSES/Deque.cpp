#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector")
#include <iostream>
#include <vector>
#define int long long 
#define inf 1000000007
#define N 500005

using namespace std;

inline void solve() {
    // dp[i][j] 從 i 到 j 第一個人選的總和
    int n;cin >> n;
    vector<int> v(n + 1), psum(n + 1);
    for(int i = 1;i <= n;i++)
        cin >> v[i];
    for(int i = 1;i <= n;i++)
        psum[i] = psum[i-1] + v[i];
    vector<vector<int> > dp(n + 1, vector<int> (n + 1));
    for(int i = 1;i <= n;i++)
        dp[i][i] = v[i];
    for(int len = 2;len <= n;len++) {
        for(int i = 1;len + i - 1 <= n;i++) {
            int j = len + i - 1;
            dp[i][j] = psum[j] - psum[i-1] - min(dp[i+1][j], dp[i][j-1]);
        }
    }
    cout << 2 * dp[1][n] - psum[n] << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}