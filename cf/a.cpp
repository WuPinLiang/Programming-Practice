#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline void solve() {
    int n;cin >> n;
    for(int i = 1;i <= n;i++)
        cout << i << ' ';
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
