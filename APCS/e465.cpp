#include <iostream>
#include <vector>
#define int long long
using namespace std;


inline void solve() {
    int m, s, n;
    cin >> m >> s >> n;
    
    int sum = 0;
    vector<int> v(n);
    for(int i = 0;i < n;i++) {
        cin >> v[i];
        sum += v[i];
    }

    int target = s - (m - sum);
    if(target == 0) {
        cout << 0 << '\n';
        return ;
    }
    vector<bool> dp(sum + 1, 0);
    dp[0] = 1;
    for(int num : v) {
        for(int j = sum;j >= num;j--) {
            //if(dp[j]) continue;
            dp[j] = dp[j] || dp[j - num];
        }
    }
    
    for(int i = target;i <= sum;i++) {
        if(dp[i]) {
            cout << i << '\n';
            return ;
        }
    }
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}

