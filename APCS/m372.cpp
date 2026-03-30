#include <iostream>
#include <vector>
#include <map>
#define int long long
#define N 250005
#define inf 1000000007
using namespace std;

//上 右 下 左
map<char, vector<int> > mp = {
  {'X', {1, 1, 1, 1}},
  {'I', {1, 0, 1, 0}},
  {'H', {0, 1, 0, 1}},
  {'L', {1, 1, 0, 0}},
  {'7', {0, 0, 1, 1}},
  {'F', {0, 1, 1, 0}},
  {'J', {1, 0, 0, 1}},
  {'0', {0, 0, 0, 0}}
};

int n, m;

inline int id(int x, int y) {
    return x * m + y;
}

vector<int> vi(N, 0), adj[N];

int cnt = 0;

inline void dfs(int u) {
    cnt++;
    for(int v : adj[u]) {
        if(vi[v]) continue;
        vi[v] = true;
        dfs(v);
    }
}

inline void solve() {
    cin >> n >> m;
    vector<vector<char> > v(n, vector<char> (m));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> v[i][j];
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            // 檢查上、下
            if(i + 1 < n and mp[v[i][j]][2] and mp[v[i + 1][j]][0]) {
                adj[id(i, j)].push_back(id(i + 1, j));
                adj[id(i + 1, j)].push_back(id(i, j));
            }
            //檢查左右
            if(j + 1 < m and mp[v[i][j]][1] and mp[v[i][j + 1]][3]) {
                adj[id(i, j)].push_back(id(i, j + 1));
                adj[id(i, j + 1)].push_back(id(i, j));
            }
        }
    }

    int ans = -inf;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            int idx = id(i, j);
            if(vi[idx]) continue;
            cnt = 0;
            dfs(idx);
            ans = max(ans, cnt);
        }
    }
    cout << ans - 1 << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
