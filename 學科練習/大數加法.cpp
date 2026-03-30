#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline void add() {
    string s, t;cin >> s >> t;
    int x = s.size(), y = t.size();
    vector<int> ans(max(x, y) + 1, 0);
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int carry = 0;
    for(int i = 0;i < max(x, y);i++) {
        int a = (i >= x) ? 0 : s[i] - '0';
        int b = (i >= y) ? 0 : t[i] - '0';
        ans[i] = carry + a + b;
        carry = ans[i] / 10;
        ans[i] = ans[i] % 10;
    }
    ans[max(x, y)] = carry;
    while(ans.size() > 1 and ans.back() == 0)
        ans.pop_back();
    reverse(ans.begin(), ans.end());
    for(int i = 0;i < ans.size();i++) {
        cout << ans[i];
    }
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    add();
    return 0;
}