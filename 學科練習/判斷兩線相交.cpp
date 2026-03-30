#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
#include <iostream>
#include <algorithm>
#include <vector>
#define int long long

using namespace std;

struct P{
    int x, y;
};

inline int cross(P a, P b, P c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// a * c == b * d

inline void solve() {
    P a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;
    int c1 = cross(a, b, c); // c 在 AB 向量的哪一邊（逆時針 or 順時針）
    int d1 = cross(a, b, d);
    int a1 = cross(c, d, a);
    int b1 = cross(c, d, b);
    
    if(c1 * d1 <= 0 and a1 * b1 <= 0) {
        cout << "YES\n";
    }else
        cout << "NO\n";
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}