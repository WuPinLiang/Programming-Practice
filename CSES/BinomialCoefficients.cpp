#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#include <iostream>
#include <vector>
#define int unsigned long long

using namespace std;

int mod = 1e9 + 7;

inline int exp(int a, int b) {
    if(b == 0ll)
        return 1ll;
    else if(b & 1)
        return a * (exp(a, b - 1) % mod) % mod;
    else {
        int half = exp(a, b / 2) % mod;
        return ((half % mod) * (half % mod)) % mod;
    }
}

vector<int> v(1000005, 1);

inline void solve() {
    int a, b;
    cin >> a >> b;
    int top = v[a] % mod;
    int bottom = ((v[b] % mod) * (v[a - b] % mod)) % mod; 
    int inv = exp(bottom, mod - 2) % mod;
    cout << ((inv % mod) * (top % mod)) % mod << '\n'; 
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    for(int i = 2;i <= 1000000;i++) {
        v[i] = ((v[i - 1] % mod) * i) % mod;
    }
    int t;cin >> t;
    while(t--)
      solve();
    return 0;
}
