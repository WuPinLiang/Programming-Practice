#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector")
#include <iostream>
#include <vector>
#define int long long 
#define mod 1000000007
#define N 1000000

using namespace std;

inline void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    vector<int> c(n);
    for(int i = 0;i < n;i++)   
        cin >> c[i];
    for(int i = 0;i < n;i++) {
        for(int j = c[i];j <= x;j++)
            dp[j] = (dp[j] + dp[j - c[i]]) % mod;
    }
    cout << dp[x] % mod << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}