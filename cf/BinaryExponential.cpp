#include <iostream>
#define int long long 
#define mod 1000000007

using namespace std;

struct matrix {
    int m[2][2] = {};
    matrix operator *(matrix b) {
        matrix result = {};
        for(int i = 0;i < 2;i++) {
            for(int j = 0;j < 2;j++) {
                for(int k = 0;k < 2;k++) {
                    result.m[i][j] += (m[i][k] * b.m[k][j]) % mod;
                    result.m[i][j] %= mod;
                }
            }
        }
        return result;
    }
};

matrix pow(matrix a, int n) {
    if(n == 1) 
        return a;
    else if(n & 1)
        return a * pow(a, n - 1);
    else {
        matrix half = pow(a, n / 2);
        return half * half;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin >> n;
    if(n == 1 or n == 0) {
        cout << n << '\n';
        return 0;
    }
    matrix t;
    t.m[0][0] = 1, t.m[1][0] = 1;
    t.m[0][1] = 1, t.m[1][1] = 0;

    matrix ret = pow(t, n - 1);
    cout << ret.m[0][0] << '\n';
    return 0;
}