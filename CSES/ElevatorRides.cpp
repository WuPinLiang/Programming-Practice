#include <iostream>
#include <vector>
#define int long long 
#define inf 1000000007

using namespace std ;
using pii = pair<int, int> ;

inline void solve() {
    int n, w;cin >> n >> w;
    vector<int> v(n);
    for(int i = 0;i < n;i++)
        cin >> v[i];
    vector<pii> dp(1 << n, {inf, inf});
    dp[0] = {1, 0};
    for(int s = 0;s < (1 << n);s++) {
        for(int i = 0;i < n;i++) {
            if((s & (1 << i)) == 0) {
                pii tmp = dp[s];
                if(tmp.second + v[i] <= w) {
                    tmp.second += v[i];
                }else {
                    tmp.first ++;
                    tmp.second = v[i];
                }
                
                if(tmp < dp[(s | (1 << i))]) {
                    dp[(s | (1 << i))] = tmp;
                }
            }
        }
    }

    //for(int s = 0;s < (1 << n);s++)
    //    cout << dp[s].first << ' ' << dp[s].second << '\n';
    cout << dp[(1 << n) - 1].first << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}

// bit-mask dp 
