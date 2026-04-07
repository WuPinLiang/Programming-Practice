#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define int long long 

using namespace std;

vector<int> memo(1000005, -1);

inline void solve() {
    int n;cin >> n;
    int N = n;
    if(memo[n] != -1) {
        cout << memo[n] << '\n';
        return ;
    }
    int ans = 1;
    unordered_map<int,int> mp;
    for(int i = 2;i * i <= n;i++) {
        while(n % i == 0) {
            mp[i]++;
            n = n / i;
        }
    }
    if(n > 1)
        mp[n]++;
    for(auto it : mp) {
        ans = ans * (it.second + 1);
    }
    memo[N] = ans;
    cout << ans << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--)
      solve();
}

// 18 = 2^1 * 3^2
// ans = (1 + 1) * (2 + 1) = 6
