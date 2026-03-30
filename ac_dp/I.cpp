#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector")
#include <iostream>
#include <vector>
#include <iomanip>
#define int long long

using namespace std;

inline void solve() {
    int n;cin >> n;
    vector<double> p(n + 1);
    for(int i = 1;i <= n;i++)
        cin >> p[i];
    // dp[i][j] 前 i 項 j 個 heads
    vector<vector<double> > dp(n + 1, vector<double> (n + 1, 0.));
    dp[0][0] = 1.;
    for(int i = 1;i <= n;i++) {
        dp[i][0] = dp[i-1][0] * (1 - p[i]);
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= i;j++) {
            dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1.0 - p[i]);
        }
    }
    int h = n / 2;
    double sum = 0.;
    for(int i = h + 1;i <= n;i++) {
        sum += dp[n][i];
    }
    cout << fixed << setprecision(10) << sum << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}