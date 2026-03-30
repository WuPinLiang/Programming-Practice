#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline void m(string s, string t) {  
    int x = s.size(), y = t.size();
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    vector<int> ans(x + y + 10, 0);
    for(int i = 0;i < x;i++) {
        for(int j = 0;j < y;j++) {
            int a = s[i] - '0';
            int b = t[j] - '0';
            ans[i + j] = a * b;
            ans[i + j + 1] = ans[i + j] / 10;
            ans[i + j] %= 10;
        }
    }
    while(ans.size() > 1 and ans.back() == 0)
        ans.pop_back();
    reverse(ans.begin(), ans.end());
    for(int i = 0;i < ans.size();i++)
        cout << ans[i];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s, t;
    while(cin >> s >> t) {
        m(s, t);
    }
    return 0;
}