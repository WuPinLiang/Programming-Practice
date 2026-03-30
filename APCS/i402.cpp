#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define inf 1000000007
using namespace std;

int n, m;

inline int solve(vector<int>& a, vector<int>& b) {
    vector<vector<int> > dp(n, vector<int>(m, 0));

    dp[0][0] = max(0ll, a[0] * b[0]);
    
    int ans = -inf;

    for(int i = 0;i < n;i++) {
        dp[i][0] = a[i] * b[0];
        ans = max(ans, dp[i][0]);
    }

    for(int j = 0;j < m;j++) {
        dp[0][j] = a[0] * b[j];
        ans = max(dp[0][j], ans);
    }

    for(int i = 1;i < n;i++) {
        for(int j = 1;j < m;j++) {
            dp[i][j] = max(dp[i-1][j-1] + a[i] * b[j], a[i] * b[j]);
            ans = max(dp[i][j], ans);
        }
    }
    return ans;
}

signed main() {
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0;i < n;i++)
        cin >> a[i];
    for(int i = 0;i < m;i++)
        cin >> b[i];

    int x = solve(a, b);
    reverse(a.begin(), a.end());
    int y = solve(a, b);
    cout << max(x, y) << '\n';
    return 0;
}
