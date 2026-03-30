#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
#include <iostream>
#include <algorithm>
#include <vector>
#define int long long

using namespace std;

inline void solve() {
    int cx, cy;
    cin >> cx >> cy;
    int a, b, c, d;
    cin >> a >> c >> d >> b;
    int ans = 0;
    if(cx >= a and cx <= d) {
        if(cy >= c and cy <= b)
            cout << 0 << '\n';
        else
            cout << min(abs(cy - b), abs(c - cy));
    }else {
        if(cy >= c and cy <= b)
            cout << min(abs(cx - d), abs(a - cx)) << '\n';
        else
            cout << min(abs(cy - b), abs(c - cy)) + min(abs(cx - d), abs(a - cx)) << '\n';
    }
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
// .(a,b)       .(d, b)


// .(a, c)      .(d, c)