#include<iostream>
#include <vector>
#define int long long
using namespace std;

const int di[4] = {0, 1, 0, -1};
const int dj[4] = {1, 0, -1, 0};

int m, n, k, r, c;

inline void solve() {
    cin >> m >> n >> k >> r >> c;
    vector<vector<int> > v(m, vector<int> (n));

    for(int i = 0;i < m;i++)
        for(int j = 0;j < n;j++)
            cin >> v[i][j];
    
    int res = 0, dir = 0, ans = 0;

    while(true) {
        //cout << r << ' ' << c << '\n';
        if(v[r][c] == 0)  break;
        res += v[r][c];v[r][c]--;
        ans ++;
        if(res % k == 0)  dir = (dir + 1) % 4;

        int ni = r + di[dir], nj = c + dj[dir];
        
        while(ni < 0 or nj < 0 or ni >= m or nj >= n or v[ni][nj] == -1) {
            dir = (dir + 1) % 4;
            ni = r + di[dir];
            nj = c + dj[dir];
        }
        r = ni;c = nj;
    }
    cout << ans << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
