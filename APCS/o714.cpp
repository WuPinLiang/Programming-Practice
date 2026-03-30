#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;
using pii = pair<int, int> ;

// dp[i] 從 0 搭到 i 下車的方法數

void solve() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<int> x;

    vector<pii> v(n);
    for(int i = 0;i < n;i++) {
        cin >> v[i].first;
        x.push_back(v[i].first);
    }
    for(int i = 0;i < n;i++) {
        cin >> v[i].second;
        x.push_back(v[i].second);
    }

    x.push_back(0);x.push_back(m);
    
    sort(x.begin(), x.end());
    for(int i = 0;i < n;i++) {
        v[i].first = lower_bound(x.begin(), x.end(), v[i].first) - x.begin();
        v[i].second = lower_bound(x.begin(), x.end(), v[i].second) - x.begin();
    }
    m = lower_bound(x.begin(), x.end(), m) - x.begin();

    sort(v.begin(), v.end(), [&](pii a, pii b) {
        return a.second < b.second;
    });

    vector<int> dp(m + 1, 0), psum(m + 1, 0);
    int last = 0;
    dp[0] = 1;
    for(auto [l, r] : v) {
        while(last < r) {
            if(last - 1 >= 0)
              psum[last] = psum[last - 1];
            psum[last] += dp[last];
            last ++;
        }

        dp[r] += psum[r - 1] - (l > 0 ? psum[l - 1] : 0); // 要用 += 因為不只有一個到 r 下車的方法
        /*
        for(int i = l;i < r;i++) {
            dp[r] += dp[i];
            dp[r] %= p
        }
        */
        dp[r] %= p;
    }
    cout << dp[m] % p << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
