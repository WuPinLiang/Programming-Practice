#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    bool ans = false;
    if(a == b or a == c or b == c) {
        if(a + b > c and a + c > b and b + c > a)
            ans = 1;
    }
    cout << ((ans) ? "Yes\n" : "No\n");
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
