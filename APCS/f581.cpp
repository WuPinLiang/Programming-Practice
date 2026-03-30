#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

inline void solve() {
    int n, m, sum = 0;
    cin >> n >> m;
    
    vector<int> v(n), prefix(2 * n, 0);
    for(int i = 0;i < n;i++) {
        cin >> v[i];
        sum += v[i];
    }
    for(int i = 0;i < 2 * n;i++) {
        prefix[i] = ((i == 0) ? v[i] : prefix[i - 1] + v[i % n]);
        cout << prefix[i] << ' ';
    }

    int u = 0;
    for(int i = 0;i < m;i++) {
        int num;cin >> num;
        num = num % sum;
        
        int v = lower_bound(prefix.begin() + u, prefix.end(), num + prefix[u]) - (prefix.begin() + u);
        v %= n;
        u = (v + 1) % n;
        cout << u << ' ';
    }
    //cout << u << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
