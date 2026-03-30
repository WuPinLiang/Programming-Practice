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
    vector<vector<double> > dp(n + 1, vector<double> (n + 1, 0));

    dp[0][0] = 1.0;
    for(int i = 1;i <= n;i++) {
        dp[i][0] = dp[i-1][0] * (1 - p[i]);
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= i;j++) {
            dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1 - p[i]);
        }
    }
    /*
    for(int i = 1;i <= n;i++) {
        //cout << p[i] << ' ';
        for(int j = 1;j <= n;j++)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }
    */
    double sum = 0;
    
    int h = n / 2;

    for(int i = h + 1;i <= n;i++)
        sum += dp[n][i];

    cout << fixed << setprecision(100) << sum << '\n';
    
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}

// 定義 dp[i][j]：考慮有 i 個有 j 個 heads 的機率和
// for every i in range (1, n) :
// for every j in range(1, i) :
// dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1 - p[i]);
