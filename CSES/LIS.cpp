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
    vector<int> v(n + 1);
    for(int i = 1;i <= n;i++) {
        cin >> v[i];
    }
    vector<int> LIS;
    for(int i = 1;i <= n;i++) {
        auto it = lower_bound(LIS.begin(), LIS.end(), v[i]);
        if(it == LIS.end())
            LIS.push_back(v[i]);
        else{
            *it = v[i];
        }
    }
    cout << LIS.size() << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}