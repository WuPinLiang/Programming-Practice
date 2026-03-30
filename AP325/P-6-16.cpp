#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

struct p{
    int l, r, w;
};

inline bool cmp(p a, p b) {
    return a.r < b.r;
}

inline void solve() {
    int n;cin >> n;
    vector<p> seg(n);
    for(int i = 0;i < n;i++) {
        cin >> seg[i].l >> seg[i].r >> seg[i].w;
    }
    vector<int> dp(n, 0);
    //dp[i] 表示前 i 個的最大收益
    sort(seg.begin(), seg.end(), cmp);
    
    vector<int> R;
    for(int i = 0;i < n;i++)    R.push_back(seg[i].r);

    dp[0] = seg[0].w;
    for(int i = 1;i < n;i++) {
        int j = lower_bound(R.begin(), R.end(), seg[i].l) - R.begin() - 1;
        dp[i] = seg[i].w;
        if(j >= 0)
            dp[i] = max(dp[i], dp[j] + seg[i].w);
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n-1] << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}

