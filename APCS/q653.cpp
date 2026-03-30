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
    sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });

    vector<int> y;
    for(int i = 0;i < n;i++) {
        y.push_back(v[i].second);
    }
    
    vector<int> lis;
    for(int i = 0;i < n;i++) {
        auto it = lower_bound(lis.begin(), lis.end(), y[i]);
        if(it == lis.end()) {
            lis.push_back(y[i]);
        }
        else {
            *it = y[i];
        }
    }

    cout << lis.size() << '\n';

    return void();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
