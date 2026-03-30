#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector")
#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> v(n), c(n);
    for(int i = 0;i < n;i++)
        cin >> c[i] >> v[i];
    
    vector<int> dp(w + 1, 0);
    for(int i = 0;i < n;i++) {
        for(int j = w;j >= c[i];j--) {
            dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
        }
    }
    cout << dp[w] << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}