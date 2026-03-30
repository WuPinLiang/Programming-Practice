#include <iostream>
#include <vector>
#define N 100005
#define inf 1000000007

using namespace std;

inline void solve() {
    int n, l;
    cin >> n >> l;
    vector<pair<int, int> > v(n + 2);
    for(int i = 1;i <= n;i++)
        cin >> v[i].first;
    for(int i = 1;i <= n;i++)
        cin >> v[i].second;
    
    v[0] = {0, 0};
    v[n + 1] = {l, 0};

    int loc[N][2] = {};
    for(int i = 0;i <= n + 1;i++) {
        loc[i][0] = i - 1;
        loc[i][1] = i + 1;
    }
    
    int i = 1, cnt = 0, mx = 0;
    while(true) {
        if(v[i].first - v[i].second >= v[loc[i][0]].first or v[i].first + v[i].second <= v[loc[i][1]].first) {
            loc[loc[i][0]][1] = loc[i][1];
            loc[loc[i][1]][0] = loc[i][0];
            cnt ++;
            mx = max(mx, v[i].second);
            if(loc[i][0] != 0)   i = loc[i][0];
            else i = loc[i][1];
        }
        else i = loc[i][1];
        if(i > n) break;
    }

    cout << cnt << '\n' << mx << '\n';

    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
