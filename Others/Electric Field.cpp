#include <iostream>
#include <vector>
#define int long long
#define mod 1000000007

using namespace std;

struct mat{
    int m[3][3] = {0};
};

inline mat mul(mat a, mat b) {
    mat ret = {};
    for(int i = 0;i < 3;i++) {
        for(int j = 0;j < 3;j++) {
            for(int k = 0;k < 3;k++) {
                ret.m[i][j] += ((a.m[i][k] % mod) * (b.m[k][j] % mod) % mod) % mod;
                ret.m[i][j] %= mod;
            }
        }
    }
    return ret;
}

mat f(mat a, int n) {
    if(n == 1)
        return a;
    if(n & 1) {
        return mul(a, f(a, n - 1));
    } 
    else {
        mat half = f(a, n / 2);
        return mul(half, half);
    }
}

inline void solve() {
    int a, b, c;
    int C1, C2, C3;
    cin >> C1 >> C2 >> C3 >> a >> b >> c;
    a = a % mod, b = b % mod, c = c % mod;
    int n;cin >> n;
    if(n == 1) {
        cout << a % mod << '\n';
        return ;
    }  
    if(n == 2) {
        cout << b % mod << '\n';
        return ;
    } 
    if(n == 3) {
        cout << c % mod << '\n';
        return ;
    } 
    mat trans;
    trans.m[0][0] = C1 % mod,trans.m[1][0] = C2 % mod, trans.m[2][0] = C3 % mod;
    trans.m[0][1] = 1, trans.m[1][1] = 0, trans.m[2][1] = 0;
    trans.m[0][2] = 0, trans.m[1][2] = 1, trans.m[2][2] = 0;
    mat ret = f(trans, n - 3);
    int ans = ((ret.m[0][0] * c) % mod + (ret.m[1][0] * b) % mod + (ret.m[2][0] * a) % mod) % mod;

    // for(int i = 0;i < 3;i++) {
    //     for(int j = 0;j < 3;j++) {
    //         cout << ret.m[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << ans % mod << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}

// a b c 
// d e f
// g h i

// 轉移矩陣：
// c1, c2, c3,
// 1, 0, 0
// 0, 1, 0