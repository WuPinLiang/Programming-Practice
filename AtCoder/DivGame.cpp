#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline void solve() {
    int n; cin >> n;
    int mx = 0;
    for(int i = 2;i * i <= n;i++) {
        if(n % i == 0) {
            n = n / i;
            mx++;
        }
    }
    if(n > 1) {
       mx++;
    }
    cout << mx << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
