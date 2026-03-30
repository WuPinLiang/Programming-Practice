#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector")
#include <iostream>
#include <vector>
#define int long long
#define N 105
#define inf 1000000007

using namespace std;

int n, w;

inline void solve() {
    cin >> n >> w;
    vector<int> v(n), c(n);
    // dp[j] 總價值是 j 所需要的最小重量
    vector<int> dp(100005, inf);
    for(int i = 0;i < n;i++) {
        cin >> c[i] >> v[i];
    }
    dp[0] = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 100000;j >= v[i];j--) {
            dp[j] = min(dp[j], dp[j - v[i]] + c[i]);
        }
    }
    for(int i = 100000;i >= 0;i--) {
        if(dp[i] != inf and dp[i] <= w) {
            cout << i << '\n';
            return ;
        }
    }
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}