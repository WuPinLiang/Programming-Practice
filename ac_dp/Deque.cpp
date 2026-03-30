#include <iostream>
#include <vector>
#define int long long 
#define N 3005
#define inf 10000000009

using namespace std;

int n;
vector<int> v(N);
vector<vector<int> > dp(N, vector<int> (N, -inf));

int f(int left, int right) {
    if(left > right)
        return 0;
    if(left == right) {
        return dp[left][left] = v[left];
    }
    if(dp[left][right] != -inf) 
        return dp[left][right];

    return dp[left][right] = max(v[left] - f(left + 1, right),
                                v[right] - f(left, right - 1)); 
}

inline void solve() {
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> v[i];
    int ans = f(1, n);
    cout << ans << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
// 定義 dp[left][right] 從 left 到 right 區間內的 X - Y 
// dp[left][right] = max(v[left] - dp[left + 1][right], (選了 left 其他就是 left + 1 ~ right 換對手選)
//                       dp[left][right - 1] + v[right] (選了 right 其他就是對手的選擇)
//                       )
