#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define int long long

using namespace std;

int a, b, c, d;

inline void solve() {
    int ans = d;
    // l = 3 的一定只能配 l = 1 的 4 + 3 + 3
    ans += c;
    a = a - 37 * c;
    ans += ceil(b / 8.0);
    a -= 8 * (b % 8);
    if(a > 0)
        ans += ceil(a / 64);
    cout << ans << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(cin >> a >> b >> c >> d) {
        solve();
    }
    return 0;
}
// 64 - 27 = 31 
// 64 / 8 = 8