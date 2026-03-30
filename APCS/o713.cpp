#include <iostream>
#include <vector>
#include <queue>
#define int long long
#define N 505
#define inf 1000000007

using namespace std;

int n, m, q;
vector<vector<int> > v(N, vector<int> (N, 0));
vector<pair<int, int> > boom;

int cal(int r) {

    int cnt = 0; 
    
    vector<vector<int> > tmp = v;

    queue<pair<int, int> > que;
    for(auto [i, j] : boom) {
        tmp[i][j] = r;
        que.push({i, j});
    }

    while(!que.empty()) {
        auto [ci, cj] = que.front();
        que.pop();
        int tr = tmp[ci][cj];

        cnt++;

        if(tr == -1)  continue;

        
        for(int i = 0;i <= tr;i++) {
            int up = ci + i, down = ci - i;
            int right = cj + (tr - i), left = cj - (tr - i);
            
            if(up < 0 or up >= n or left < 0 or left >= m and tmp[up][left] > 0)  continue;
            else que.push({up, left});
            
            if(up < 0 or up >= n or right < 0 or right >= m and tmp[up][right] > 0)  continue;
            else que.push({up, right});

            if(down < 0 or down >= n or left < 0 or left >= m and tmp[down][left] > 0)  continue;
            else que.push({down, left});

            if(down < 0 or down >= n or right < 0 or right >= m and tmp[down][right] > 0)  continue;
            else que.push({down, right});
        } 
    }
    return cnt ;
}

int bs(int left, int right) {
    int mn = inf;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(cal(mid) > q) {
            mn = min(mn, mid);
            right = mid - 1;
        }
    
        else if (cal(mid) == q) {
            return mid ; 
        }

        else {
            left = mid + 1;
        }
        cout << left << ' ' << right << '\n';  
    }
    return mn ;
}

void solve() {
    cin >> n >> m >> q;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> v[i][j];
            if(v[i][j] == -2) {
                boom.push_back({i, j});
            } 
        }
    }
    int ans = bs(0, N);
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}
