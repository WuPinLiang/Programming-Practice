#include <iostream>
#define int long long
using namespace std;
const int mod = 1000000007; 
signed main() {
    int n;cin >> n;
    if(n == 0) {
        cout << 0 << '\n'; // by definition
        return 0;
    }
    int a = 1, b = 1, c = 1;
    for(int i = 3;i <= n;i++) {
        c= (a + b) % mod;
        a = b, b = c;
    }
    cout << c << '\n';
    return 0;
}

