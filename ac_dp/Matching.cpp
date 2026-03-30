#pragma GCC optimze ("Ofast, no-stack-protecter, unroll-loops, fast-math, O3")
#include <iostream>
#include <vector>
#define int long long 
#define mod 1000000007

using namespace std ;

inline void solve() {
    int n;cin >> n;
    vector<vector<int> > v(n, vector<int> (n));
    for(int i = 0;i < n;i++) 
        for(int j = 0;j < n;j++)
            cin >> v[i][j];
    
    vector<int> dp((1 << n));

    dp[0] = 1;

    for(int s = 0;s < (1 << n);s++) {
        int man = 0;
        for(int i = 0;i < n;i++) {
            if(s & (1 << i)) {
                man++;
            }
        }
        for(int i = 0;i < n;i++) {
            int girl = (1 << i);
            if((s & girl) == 0 and v[man][i] == 1) {
                dp[s | girl] += dp[s];
                dp[s] %= mod;
            }
        } 
    }

    //for(int s = 0;s < (1 << n);s++)
    //    cout << dp[s] << '\n';

    cout << dp[(1 << n) - 1] % mod << '\n';
    return ;
} 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}

// bit mask dp
// dp[s] = 女生集合 s 的方法數
// 轉移的時候可以對於男生的
