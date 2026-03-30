#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

inline void solve() {
    string s, t;cin >> s >> t;
    int x = s.size(), y = t.size();
    if(x < y) {
        cout << '-';
        swap(s, t);
        swap(x, y);
    }else if(x == y) {
        if(s[0] < t[0]) {
            cout << '-';
            swap(s, t);
            swap(x, y);
        }
    }
    vector<int> ans(max(x, y), 0);
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int borrow = 0;
    for(int i = 0;i < max(x, y);i++) {
        int a = (i >= x) ? 0 : s[i] - '0' - borrow;
        int b = (i >= y) ? 0 : t[i] - '0';
        if(b > a) {
            borrow = 1;
            a += 10;
        }else  
            borrow = 0;
        ans[i] = a - b;
    }
    while(ans.size() > 1 and ans.back() == 0)
        ans.pop_back();
    reverse(ans.begin(), ans.end());
    for(int i = 0;i < ans.size();i++)
        cout << ans[i];
    cout << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) {
        solve();   
    }
    return 0;
}