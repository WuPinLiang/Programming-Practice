#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline void solve() {
    int n;cin >> n;
    vector<vector<int> > v(n, vector<int> (3));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < 3;j++)
            cin >> v[i][j];
    }
    int p;cin >> p;
    vector<pair<int, int> > q(p);
    for(int i = 0;i < p;i++)
        cin >> q[i].first >> q[i].second;   
    int pos = 0, neg = 0;
    for(int i = 0;i < p;i++) {
        for(int j = 0;j < n;j++) {
            if(v[j][0] * q[i].first + v[j][1] * q[i].second + v[j][2] > 0)
                pos++;
            else
                neg++;
        }
    }
    cout << pos * neg << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}