#include <iostream>
#include <vector>
#define int long long 

using namespace std;

inline void solve() {
    int n;cin >> n;
    int ans = n;
    for(int i = 2;i * i <= n;i++) {
        if(n % i == 0) {
            while(n % i == 0) {
              n /= i;
            }
            ans = ans - (ans / i);
        }
    }
    if(n > 1)
        ans = ans - (ans / n);
    cout << ans << '\n';
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
