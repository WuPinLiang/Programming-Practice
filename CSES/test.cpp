#include <iostream>
#include <numeric>
using namespace std;

inline void solve() {
    int a, b;
    cin >> a >> b;
    cout << "GCD : " << __gcd(a, b) << '\n';
    cout << "LCM : " << a * b / __gcd(a, b) << '\n';
    return ;
}
signed main() {
    solve();
    return 0;
}
