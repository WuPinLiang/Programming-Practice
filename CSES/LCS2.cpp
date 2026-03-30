#include <iostream>
#include <vector>
#include <algorithm>
#define int long long 

using namespace std ;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    for(int i = 1;i <= m;i++)
        cin >> b[i];
    vector<vector<int> > dp(n + 1, vector<int> (m + 1, 0));
    
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            if(a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }
    
    cout << dp[n][m] << '\n';
    int i = n, j = m;
    vector<int> ans ;
    while(i >= 1 and j >= 1) {
        if (a[i] == b[j]) {
            ans.push_back(a[i]); // <-- 修正這行
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    for(int cur : ans)
        cout << cur << ' ';
    cout << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve() ;
    return 0;
}
