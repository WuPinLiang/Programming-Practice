#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

inline void solve() {
    int n;cin >> n;
    vector<pair<int, int> > v(n);
    for(int i = 0;i < n;i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), [] (pair<int, int> a, pair<int, int> b) {
        return a.first < b.first ;
    }); 

    int ans = 0, last_begin = v[0].first, last_end = v[0].second;
    for(int i = 1;i < n;i++) {
        if(v[i].first > last_end) {
            ans += (last_end - last_begin);
            last_begin = v[i].first;
            last_end = v[i].second;
        }
        else {
            last_end = max(last_end, v[i].second);
        }
    }
    ans += (last_end - last_begin);
    cout << ans << '\n';
    return ;
}

signed main() {
    solve();
    return 0;
}
