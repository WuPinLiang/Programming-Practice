#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#include <iostream>
#include <vector>
#define int long long

using namespace std;
const int mod = 1000000007;

inline int exp(int a, int b) {
    if(b == 0)
        return 1;
    else {
        if(b & 1) {
            return (a * exp(a, b - 1)) % mod;
        }
        int half = exp(a, b / 2);
        half = half % mod;
        return (half * half) % mod; 
    }
}

inline void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int base = exp(a, b) % mod;
    cout << exp(base, c) % mod << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--)
      solve();
    return 0;
}
