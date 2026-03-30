#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#define int long long

using namespace std;

inline void solve() {
    double n;cin >> n;
    double pi = acos(-1);
    double ans = n * sin(pi / n);
    cout << fixed << setprecision(2) << pi << ' ' << sin(pi / n) << '\n';
    cout << fixed << setprecision(2) << scientific << ans << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}