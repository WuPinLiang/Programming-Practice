#include <iostream>
#include <vector>
#define int long long
#define inf 1000000007

using namespace std;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v, dp(n, vector<int> (m));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> v[i][j];
        }
    }
    
    dp[0][0] = v[0][0];
     // 定義 dp[i][j] 到 v[i][j] 能拿到的最大收益，並且做後一次
    // dp[i][j] = max(dp[i-1][j] , dp[i+1][j], dp[i][j-1]) + v[i][j];
    // 這個轉移式是錯的，因為你可能會一直繞圈圈

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(i > 0)
              dp[i][j] = max(dp[i][j], dp[i-1][j] + v[i][j]);
            if(i + 1 < m)
              dp[i][j] = max(dp[i][j], dp[i+1][j] + v[i][j]);
            if(j - 1 >= 0)
              dp[i][j] = max(dp[i][j], dp[i][j - 1] + v[i][j]);
        }
    }
    int ans = -inf;
    for(int j = 0;j < m;j++) {
        ans = max(ans, dp[n-1][j]);
        cout << dp[n-1][j] << ' ';
    }
    
    return ;
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
