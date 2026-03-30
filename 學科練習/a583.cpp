#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
#include <vector>
#define int long long

using namespace std;

inline void solve() {
    int m;
    cin >> m >> m;
    vector<int> x(m), y(m);
    for(int i = 0;i < m;i++)
        cin >> x[i] >> y[i];
    double mn = 1e9 + 7 * 1.;
    for(int i = 0;i < m;i++) {
        for(int j = i + 1;j < m;j++) {
            double d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            //cout << d << ' ';
            mn = min(mn, d);
        }
    }
    cout << fixed << setprecision(4) << mn;
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}