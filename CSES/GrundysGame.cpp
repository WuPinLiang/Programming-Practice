#include <iostream>
#include <vector>
 
using namespace std;
 
inline void solve() {
    int x; cin >> x;
    vector<int> dp(x + 1);
    
    for(int i = 3;i <= x;i++) {
        int m = i / 2;
        for(int j = 1;j < m;j++) {
            if(i - j >= 0 and !dp[i - j])
                dp[i] = 1;
        }
    }
    for(int i = 0;i <= x;i++)
        cout << dp[i] << ' ';
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
 
 
 
// 定義 dp[i] 
// dp[0....mn] = 0;
// dp[i] = (dp[i - choice[i]])
