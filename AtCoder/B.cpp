#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n, 0);
    for(int i = 0;i < k;i++) {
        int a, b;
        cin >> a >> b;
        v[a]++;
    }
    for(int i = 0;i < k;i++) {
        if(v[i] == )
    }
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}