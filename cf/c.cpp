#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protecter")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define int long long

using namespace std;

inline void solve() {
    int n;cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n;i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), [&](int a, int b) {
        return a < b;
    });
    int mx = 0;
    for(int i = 0;i < n;i++) {
        int d = v[i];
        set<int> st;
        for(int j = 0;j < n;j++)
            st.insert(v[j] - d);
        int num;
        for(int j = 0;j < n + 5;j++) {
            if(!st.count(j)) {
                num = j;
                break;
            }
        }
        mx =  max(mx, num);
    }
    cout << mx << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--)
      solve();
    return 0;
}
