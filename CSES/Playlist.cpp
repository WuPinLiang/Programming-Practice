#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define int long long 
#define N 500005

using namespace std;
const int inf = 1e18;

inline void solve() {
    int n;cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n;i++) 
        cin >> v[i];
    map<int, int> mp;
    int ans = 0;
    int left = 0;
    for(int right = 0;right < n;right++) {
        while(left < n and mp.count(v[right])) {
            mp[v[left]]--;
            if(mp[v[left]] == 0)
                mp.erase(v[left]);
            left++;
        }
        ans = max(ans, right - left + 1);
        mp[v[right]] ++;
    }
    cout << ans << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}