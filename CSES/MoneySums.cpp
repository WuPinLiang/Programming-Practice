#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long 
#define N 500005

using namespace std;
const int inf = 1e18;

inline void solve() {
    int n;cin >> n;
    vector<int> v(n);
    int sum = 0;
    for(int i = 0;i < n;i++) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    vector<int> dp(sum + 1, 0);
    dp[0] = 1, dp[sum] = 1;
    for(int i = 0;i < n;i++) {
        for(int j = sum;j >= 0;j--) {
            if(j - v[i] >= 0 and dp[j - v[i]])
                dp[j] = 1;
        }
    }
    vector<int> ans;
    for(int i = 1;i <= sum;i++) {
        if(dp[i])
            ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(int x : ans)
        cout << x << ' ';
    cout << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}