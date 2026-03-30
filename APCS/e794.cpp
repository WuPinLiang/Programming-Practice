#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline void solve() {
    int n;cin >> n;
    vector<int> dp(n + 2, 0);
    dp[0] = 0, dp[1] = 1;
    for(int i = 2;i <= n + 1;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n] << ':' << dp[n+1] << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}

//0 1 1 2 3 5 8 13 21 34
