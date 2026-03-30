#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#define int long long

using namespace std;

const int inf = 1e18;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(n + 1, vector<int> (m + 1));
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            cin >> v[i][j];

    vector<vector<int> > dp(n + 1, vector<int> (m + 1));

    // dp[i][j]表示走到 v[i][j] 的最大收穫
    // 對於每一行，有可能來自上面，左邊或右邊，所以維護兩個陣列 right, left 分別表示從左到右，以及從右往左的最大值
    // 最後 dp[i][j] 就會是 max(right[j], left[j])

    for(int i = 1;i <= n;i++) {
        vector<int> left(m + 1, 0);
        for(int j = 1;j <= m;j++) {
            if(j == 1)  left[j] = dp[i-1][j] + v[i][j];
            else {
                left[j] = max(left[j-1], dp[i-1][j]) + v[i][j];
            }
        }

        vector<int> right(m + 1, 0);
        for(int j = m;j >= 1;j--) {
            if(j == m) {
                right[j] = dp[i-1][j] + v[i][j];
            }else {
                right[j] = max(right[j + 1], dp[i-1][j]) + v[i][j];
            }
        }

        for(int j = 1;j <= m;j++) {
            dp[i][j] = max(right[j], left[j]);
        }
    }

    int ans = -inf;
    for(int j = 1;j <= m;j++) {
        ans = max(ans, dp[n][j]);
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