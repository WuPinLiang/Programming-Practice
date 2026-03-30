#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector")
#include <iostream>
#include <vector>
#define int long long
#define inf 1000000000000000000

using namespace std;

inline void solve() {
    int n;cin >> n;
    vector<int> v(n + 1), psum(n + 1, 0);
    for(int i = 1;i <= n;i++) 
        cin >> v[i], psum[i] = psum[i-1] + v[i];
    
    vector<vector<int> > dp(n + 1, vector<int> (n + 1, 0));
    for(int i = 1;i <= n;i++)
        dp[i][i] = 0;
    for(int len = 2;len <= n;len++) {
        for(int i = 1;i + len - 1 <= n;i++) {
            int j = i + len - 1;
            int mn = inf; 
            for(int mid = i;mid < j;mid++) {
                mn = min(mn, psum[j] - psum[i - 1] + dp[i][mid] + dp[mid + 1][j]);
            }
            dp[i][j] = mn;
        }
    }
    cout << dp[1][n] << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}