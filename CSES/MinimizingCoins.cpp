#include <iostream>
#include <vector>
#define int long long 
#define inf 1000000007
#define N 1000005

using namespace std;

inline void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> c(n+1);
    for(int i = 1;i <= n;i++)
        cin >> c[i];
    // dp[i] 湊出 i 圓的最小硬幣數量
    // dp[i] = min(dp[i], dp[i - coins[j]] + 1)
    vector<int> dp(x + 1, inf);
    dp[0] = 0;
    for(int i = 1;i <= x;i++) {
        for(int j = 1;j <= n;j++) {
            if(i - c[j] >= 0)
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
        }
    }
    cout << ((dp[x] == inf) ? -1 : dp[x]) << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}