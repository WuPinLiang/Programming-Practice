#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
#include <iostream>
#include <algorithm>
#include <vector>
#define int long long

using namespace std;

int n;

inline void solve() {
    vector<char> v(n);
    for(int i = 0;i < n;i++)
        cin >> v[i];
    for(int i = 0;i < n;i++) {
        if(v[i] >= 'a' and v[i] <= 'z')
            cout << (char)('A' + (v[i] - 'a'));
        else
            cout << (char)('a' + (v[i] - 'A'));
    }
    cout << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(cin >> n)
        solve();
    return 0;
}