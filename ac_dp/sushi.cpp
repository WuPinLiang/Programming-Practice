#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#define int long long
#define inf 1000000007

using namespace std;

double dp[305][305][305];
int n;

double f(int x, int y, int z) {
    if(x == 0 and y == 0 and z == 0)
        return 0.0;
    if(dp[x][y][z] != 0.0) 
        return dp[x][y][z];
    dp[x][y][z] = 0.0;
    if(x - 1 >= 0)
        dp[x][y][z] += f(x - 1, y, z) * x;
    if(y - 1 >= 0)
        dp[x][y][z] += f(x + 1, y - 1, z) * y;
    if(z - 1 >= 0)
        dp[x][y][z] += f(x, y + 1, z - 1) * z;
    dp[x][y][z] = (dp[x][y][z] + (double)n) / (double)(x + y + z);
    return dp[x][y][z];
}

inline void solve() {
    int c1 = 0, c2 = 0, c3 = 0;
    cin >> n;
    vector<int> v(n + 1);
    for(int i = 1;i <= n;i++) {
        cin >> v[i];
        //cerr << v[i] << endl;
        if(v[i] == 1) c1++;
        else if(v[i] == 2)  c2++;
        else if(v[i] == 3)  c3++;
    }
    memset(dp, 0.0, sizeof(dp));
    cout << fixed << setprecision(20) <<  f(c1, c2, c3) << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}

// 定義 dp[x][y][z] 對於剩下 1 個壽司的盤子 x 個，(2, y), (3, z) 期望所需要的步驟數
// dp[x][y][z] = 1 + 1/3(x - 1, y, z) + 1/3(x + 1, y - 1, z) + 1/3(x, y + 1, z - 1);
