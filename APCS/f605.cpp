#include <iostream>
#include <vector>
#define inf 1000000007
#define int long long
using namespace std;

inline void solve() {
    int n, d;
    cin >> n >> d;
    vector<vector<int> > v(n, vector<int> (3, 0));
    vector<int> ans;
    for(int i = 0;i < n;i++) {
        int sum = 0;
        int mx = -inf, mn = inf;
        for(int j = 0;j < 3;j++) {
            cin >> v[i][j];
            mn = min(mn, v[i][j]);
            mx = max(mx, v[i][j]);
            sum += v[i][j];
        }
        if(mx - mn >= d) {
            ans.push_back(sum / 3);
        }
    }

    cout << ans.size() << ' ';
    int num = 0;
    for(int x : ans)
        num += x;
    cout << num << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
