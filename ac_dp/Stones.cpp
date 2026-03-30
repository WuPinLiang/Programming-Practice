#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline void solve() {
    int n, p;cin >> n >> p;
    vector<int> v(n + 1), dp(p + 1, 0);
    for(int i = 1;i <= n;i++)
        cin >> v[i];
    for(int i = 1;i <= p;i++) {
        for(int j = 1;j <= n;j++) {
            if(i - v[j] >= 0 and dp[i - v[j]] == 0)
                dp[i] = 1;
        }
    }
    //for(int i = 1;i <= p;i++)
    //    cout << dp[i] << ' ';
    cout << (dp[p] ? "First\n" : "Second\n");
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
// 定義 dp[i] 表示拿到 i 個石頭的局面會贏或輸
// dp[i] = 1 if(dp[i - choice[j]] == 0)
