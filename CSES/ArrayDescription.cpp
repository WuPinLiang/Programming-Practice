#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector")
#include <iostream>
#include <vector>
#define int long long 
#define mod 1000000007
#define N 500005

using namespace std;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > dp(n + 1, vector<int> (105, 0));
    vector<int> v(n + 1);
    for(int i = 1;i <= n;i++) {
        cin >> v[i];
    }
    // dp[i][j] 表示第 i 個位置選 j 的陣列數量
    if(v[1] == 0) {
        for(int i = 1;i <= m;i++)
            dp[1][i] = 1;
    }
    else {
        dp[1][v[1]] = 1;
    }
    for(int i = 2;i <= n;i++) {
        if(v[i] == 0) {
            for(int j = 1;j <= m;j++) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j + 1]) % mod;
            }
        }
        else {
            dp[i][v[i]] = (dp[i-1][v[i] - 1] + dp[i-1][v[i]] + dp[i-1][v[i] + 1]) % mod;
        }
    }
    int ans = 0;
    for(int i = 1;i <= m;i++)
        ans = (ans + dp[n][i]) % mod;
    cout << ans << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}