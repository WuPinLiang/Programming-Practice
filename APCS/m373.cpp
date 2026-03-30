#include <iostream>
#include <vector>
#define int long long
#define inf 1000000007

using namespace std;

inline void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0;i < n;i++) {
        cin >> v[i];
    }

    vector<vector<int> > dp(n, vector<int> (k + 1, 0));

    //dp[0][0] = max(0ll, v[0]);
    //dp[0][1] = 0;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j <= k;j++) {
            if(i - 1 >= 0)  dp[i][j] = max(dp[i][j], dp[i-1][j] + v[i]);
            if(i - 1 >= 0 and j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            dp[i][j] = max(dp[i][j], v[i]);
        }
    }
    
    int ans = -inf;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j <= k;j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << '\n';

    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}

/*

   dp[i][j] 結尾在 i 且用了j 次金牌的最大獲益
   dp[i][j] = max { dp[i-1][j] + v[i],
                    dp[i-1][j - 1],
                    v[i]
                  }
    ans : max(dp[n - 1][j = 0 ~ k]);
*/
