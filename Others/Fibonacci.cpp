#include <iostream>
#include <vector>
#define int long long
#define mod 1000000007

using namespace std;

struct matrix {
    int m[2][2] = {};
    matrix operator *(matrix b) {
        matrix ret;
        for(int i = 0;i < 2;i++) {
            for(int j = 0;j < 2;j++) {
                for(int k = 0;k < 2;k++) {
                    ret.m[i][j] += (m[i][k] % mod * b.m[k][j] % mod) % mod;
                    ret.m[i][j] %= mod; 
                }
            }
        }
        return ret;
    }
};

inline matrix pow(matrix a, int n) {
    if(n == 1)
        return a;
    else if(n & 1)
        return a * pow(a, n - 1);
    else {
        matrix half = pow(a, n / 2);
        return half * half;
    }
}

inline void solve() {
    int x1, x2, a, b, n;
    cin >> x1 >> x2 >> a >> b >> n;
    matrix t;
    t.m[0][0] = b, t.m[1][0] = a;
    t.m[0][1] = 1, t.m[1][1] = 0;
    matrix ret = pow(t, n - 2);
    cout << ((ret.m[0][0] * x2) % mod + (ret.m[1][0] * x1) % mod) % mod << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}