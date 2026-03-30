#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline void norm(string &s) {
    int i = 0;
    while(i < s.size() and s[i] == '0') {
        i++;
    }
    if(i == s.size())
        s = "0";
    else
        s = s.substr(i);
    return ;
}


string sub_ge(string a, string b) {
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
    norm(c);
    return c;
}

inline int cmp(string a, string b) {
    norm(a); norm(b);
    if (a.size() != b.size()) return (a.size() < b.size()) ? -1 : 1;
    if (a == b) return 0;
    return (a < b) ? -1 : 1;
}

inline string devide(string s, string t) {
    norm(s);norm(t);
    if(t == "0")
        return "WTF\n";
    else if(cmp(s, t) == -1)
        return "0\n";
    string q; q.reserve(s.size());
    string rest = "0";
    for(char c : s) {
        if(rest == "0")
            rest = string(1, c);
        else
            rest.push_back(c);
        norm(q);

        int digit = 0;
        while(cmp(rest, t) >= 0) {
            digit++;
            rest = sub_ge(rest, t);
        }
        
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s, t;
    cin >> s >> t;
    devide(s, t);
    return 0;
}