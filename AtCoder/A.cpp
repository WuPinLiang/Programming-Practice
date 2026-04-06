#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline void solve() {
    int n;cin >> n;
    cout << n;
    for(int i = n - 1;i > 0;i--)
        cout << ',' << i;
    cout << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
