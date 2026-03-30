#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector")
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long 
#define inf 1000000007
#define N 10005

using namespace std;

const int di[4] = {1, -1, 0, 0};
const int dj[4] = {0, 0, 1, -1};
const char dirc[4] = {'D', 'U', 'R', 'L'};
//D, U, R, L

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> > v(n, vector<char> (m));
    int bi, bj, ei, ej;
    for(int i = 0;i < n;i++) {  
        for(int j = 0;j < m;j++) {
            cin >> v[i][j];
            if(v[i][j] == 'A') 
                bi = i, bj = j;
            if(v[i][j] == 'B')
                ei = i, ej = j;
        }
    }
    vector<vector<int> > vis(n, vector<int> (m, 0)), pa(n, vector<int> (m, -1));
    queue<pair<int, int> > q;
    vis[bi][bj] = 1;
    q.push({bi, bj});
    bool fnd = false;
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if(cur.first == ei and cur.second == ej) {
            fnd = true;
            break;   
        }
        for(int dir = 0;dir < 4;dir++) {
            int ni = cur.first + di[dir];
            int nj = cur.second + dj[dir];
            if(ni < 0 or nj < 0 or ni >= n or nj >= m or v[ni][nj] == '#' or vis[ni][nj]) 
                continue;
            vis[ni][nj] = 1;
            q.push({ni, nj});
            pa[ni][nj] = dir;
        }
    }

    if(!fnd) {
        cout << "NO\n";
        return ;   
    }
    cout << "YES\n";
    string ans = "";
    while(ei != bi or ej != bj) {
        int cur = pa[ei][ej];
        ei = ei - di[cur];
        ej = ej - dj[cur];
        ans += dirc[cur];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n' << ans << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}