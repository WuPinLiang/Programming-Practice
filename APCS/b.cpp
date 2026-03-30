#include <iostream>
#include <vector>
#include <map>
#define int long long
using namespace std;

int d[4][2] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

inline void solve() {
    int n, m, t, k;
    cin >> n >> m >> t >> k;

    int ci = (n + 1) / 2, cj = (m + 1) / 2;
    t--;
    int dx = d[t][0], dy = d[t][1];
    for(int i = 0;i < k;i++) {
        int dist_x = (dx == 1) ? n - ci : ci - 1;
        int dist_y = (dy == 1) ? m - cj : cj - 1;

        int step = min(dist_x, dist_y);
      
        ci += dx * step;
        cj += dy * step;

        if(dist_x == dist_y) {
            dx = -dx;
            dy = -dy;
        }else if(dist_x > dist_y) {
            dy = -dy;
        }else {
            dx = -dx;
        }
    }

    cout << ci << ' ' << cj << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
