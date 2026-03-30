#include <iostream>
#include <vector>

using namespace std;

inline void solve() {
    int x, n;cin >> x >> n;
    vector<int> v(n), dp(x + 1);
    for(int i = 0;i < n;i++) {
        cin >> v[i];
    }

    for(int i = 0;i <= x;i++) {
        for(int j = 0;j < n;j++) {
            if(i - v[j] >= 0 and  !dp[i - v[j]])
                dp[i] = 1;
        }
    }
    for(int i = 1;i <= x;i++)
        cout << "LW"[dp[i]];
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
