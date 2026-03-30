#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector")
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long 
#define inf 1000000007
#define N 500005

using namespace std;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n + 1), t(m + 1);
    for(int i = 0;i < n;i++)
        cin >> s[i];
    for(int i = 0;i < m;i++)
        cin >> t[i];
    vector<vector<int> > dp(n + 1, vector<int> (m + 1));
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << '\n';
    int i = n, j = m;
    vector<int> ans;
    while(i > 0 and j > 0) {   
        if(s[i-1] == t[j-1]) {
            ans.push_back(s[i-1]);
            i--, j--;
        }else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        }else
            j--;
    }
    reverse(ans.begin(), ans.end());
    for(int num : ans)  
        cout << num << ' ';
    cout << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}