#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protecter")
#include <iostream>
#include <algorithm>
#include <vector>
#define int long long

using namespace std;

inline void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> v(n), v2(n);
    for(int i = 0;i < n;i++) {
        cin >> v[i];
    }
    v2 = v;
    for(int i = 0;i < m;i++) {
        int b, c;cin >> b >> c;
        b--;
        v[b] = v[b] + c;
        if(v[b] > h)
            v = v2;
    }
    for(int i = 0;i < n;i++)
        cout << v[i] << ' ';
    cout << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) 
      solve();
    return 0;
}
