#include <iostream>
#include <vector>
#include <set>
#define int long long
using namespace std;

inline void solve() {
    int n, l;
    cin >> n >> l;
    vector<int> v(n + 1);
    for(int i = 0;i < n;i++) {
        int x, num;cin >> x >> num;
        v[num] = x;
    }
    
    set<int> st;
    st.insert(0);st.insert(l);

    int ans = 0;
    for(int i = 1;i <= n;i++) {
        auto it1 = st.upper_bound(v[i]);
        auto it2 = --st.upper_bound(v[i]);
        
        int right = *it1, left = *it2;

        //cout << right - left << '\n';

        ans += (right - left);
    
        st.insert(v[i]);
    }

    cout << ans << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
