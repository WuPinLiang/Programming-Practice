#include <iostream>
#include <vector>
#include <string>
#define int long long
#define inf 1000000007
#define N 100005

using namespace std;

vector<int> v(N), dp(N, inf);
int n, k;

inline int f(int num) {
    if(num == 0)
        return 0;
    if(dp[num] != inf)
        return dp[num];
    int mn = inf;
    for(int i = max(0ll, num - k);i < num;i++) {
        mn = min(mn, f(i) + abs(v[i] - v[num]));
    }
    return dp[num] = mn;
}

inline void solve() {
    cin >> n >> k;
    for(int i = 0;i < n;i++)
        cin >> v[i];
    // dp[i] 到達 i 的最小花費
    cout << f(n - 1) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
