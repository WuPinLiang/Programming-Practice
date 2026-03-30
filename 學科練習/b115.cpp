#include <iostream>
#include <vector>
#define int long long

using namespace std;
// s > t -> 1
// s = t -> 0
// s < t -> -1
inline int cmp(string s, string t) {
    if(s.size() > t.size())
        return 1;
    else if(s == t)
        return 0;
    else
        return -1;
}

inline string sub(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string c;
    int borrow = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        int x = (a[i] - '0') - borrow;
        int y = (i < (int)b.size()) ? (b[i] - '0') : 0;
        if (x < y) { x += 10; borrow = 1; }
        else borrow = 0;
        c.push_back(char('0' + (x - y)));
    }
    while (c.size() > 1 && c.back() == '0') c.pop_back();
    reverse(c.begin(), c.end());
    return c;
}

inline string d(string s, string t) {
    string ans;
    if(cmp(s, t) < 1)   return "0";
    string ret = "0";
    while(cmp(s, t) == 1) {
        s = sub(s, t);
        
    }
    return ans;
}

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
    string s, t;char opt;
    while(cin >> s >> opt >> t) {
        if(opt == '/') {
            cout << d(s, t) << '\n';
        }else {
            m(s, t);
        }
    }
    return 0;
}