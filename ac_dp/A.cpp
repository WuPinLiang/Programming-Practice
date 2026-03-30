#include <iostream>
#include <vector>
#include <string>
#define int long long
#define inf 1000000007

using namespace std;


inline void solve() {
    int n;cin >> n;
    vector<int> v(n + 1);
    for(int i = 1;i <= n;i++)
        cin >> v[i];
    vector<int> dp(n + 1, 0);
    dp[1] = 0;dp[2] = abs(v[1] - v[2]);
    for(int i = 3;i <= n;i++) {
        dp[i] = min(dp[i-1] + abs(v[i] - v[i-1]), dp[i-2] + abs(v[i] - v[i-2]));
    }
    cout << dp[n] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
