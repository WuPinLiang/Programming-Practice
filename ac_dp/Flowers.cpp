#pragma optimize ("Ofast, no-stack-protecter, unroll-loops, fast-math, O3")
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define lowbit(x) (x & (-x))
#define N 2000005
#define inf 100000000000007

using namespace std;

vector<int> bit(N, -inf);

inline int query(int idx) {
    int mx = -inf;
    for(int i = idx;i > 0;i -= lowbit(i))
        mx = max(mx, bit[i]);
    return mx;
}

inline void update(int idx, int val) {
    for(int i = idx;i < N;i += lowbit(i)) {
        bit[i] = max(val, bit[i]);
    }
    return ;
}

inline void solve() {
    int n;cin >> n; 
    vector<int> h(n), a(n);
    for(int i = 0;i < n;i++)
        cin >> h[i];
    for(int i = 0;i < n;i++)
        cin >> a[i];

    vector<int> dp(n, -inf);
    for(int i = 0;i < n;i++) {
        int tmp = query(h[i] - 1) + a[i];
        dp[i] = max(a[i], tmp);
        update(h[i], dp[i]);
    }
    int mx = -inf;
    for(int i = 0;i < n;i++)
        mx = max(mx, dp[i]);
    cout << mx << '\n';
    // 本來是寫 dp[n - 1]
    // 但是不一定是最後最大
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
// 帶權 LIS 
// 定義 dp[i] 從頭到 i 的最大值
// d[i] = max{dp[0],.... dp[i-1]} + a[i];
