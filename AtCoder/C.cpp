#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#include <iostream>
#include <vector>
#include <cmath>
#define int long long

using namespace std;

inline void solve() {
    int n;cin >> n;
    int lg = log2(n), cnt = 0;
    for(int i = 1;i <= lg;i++) {
       cnt += ((sqrt(n / (1ll << i)) + 1) / 2);
    }
    cout << cnt << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
