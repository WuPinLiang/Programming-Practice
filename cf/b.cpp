#include <iostream>
#include <vector>
#define int long long 

using namespace std;

inline void solve() {
    int n;cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n;i++)
        cin >> v[i];
    int ans = -1;
    for(int i = 0;i < n;i++) {
        for(int j = i;j < n;j++) {
            vector<int> tmp = v;
            tmp[i] = v[j], tmp[j] = v[i];
            int sum = 0, mx = -1;
            for(int k = 0;k < n;k++) {
                mx = max(mx, tmp[k]);
                sum += mx;
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << '\n';
    return void();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;cin >> t;
    while(t--) 
      solve();
    return 0;
}
