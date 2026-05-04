#include <iostream>
#include <vector>
#define int long long
using namespace std;

inline void solve() {
    int n; cin >> n;
    vector<int> v(n + 1), idx(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        idx[v[i]] = i;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] != i) {
            ans++;
            int j = idx[i];        
            idx[v[i]] = j;
            swap(v[i], v[j]);
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}