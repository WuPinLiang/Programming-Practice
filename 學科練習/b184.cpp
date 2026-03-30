#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
#include <iostream>
#include <algorithm>
#include <vector>
#define int long long

using namespace std;

int n;

inline void solve() {
    vector<int> v(n + 1, 0), c(n + 1, 0);
    for(int i = 1;i <= n;i++) {
        cin >> c[i] >> v[i];
    }
    vector<int> dp(105, 0);

    for(int i = 1;i <= n;i++) {
        for(int j = 100;j >= c[i];j--) {
            dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
        }
    }
    cout << dp[100] << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(cin >> n) {
        solve();
    }
    return 0;
}