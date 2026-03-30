// WA 58%
#pragma GCC optimize("Ofast,no-stack-protector")
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define int long long

using namespace std;

const int di[4] = {1, -1, 0, 0};
const int dj[4] = {0, 0, 1, -1};

struct Node {
    int x, y, t;
};


inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> > v(n, vector<char> (m));
    vector<vector<int> > vis(n, vector<int> (m, 0));
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> v[i][j];
    queue<Node> q;
    // x, y, time
    int ans = 0;
    int t;cin >> t;
    for(int i = 0;i < t;i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if(vis[x][y] == 0) {
            ans++;
            vis[x][y] = 1;   
            q.push({x, y, i});
        }
        while(!q.empty() and q.front().t < i) {
            auto cur = q.front();
            q.pop();
            for(int dir = 0;dir < 4;dir++) {
                int ni = cur.x + di[dir];
                int nj = cur.y + dj[dir];
                if(ni < 0 or nj < 0 or ni >= n or nj >= m or vis[ni][nj] or v[ni][nj] == '#') {
                    continue ;
                }
                vis[ni][nj] = 1;
                ans ++;
                q.push({ni, nj, cur.t + 1});
            }
        }
        cout << ans << '\n';
    }
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}