#include <iostream>
#include <vector>
#include <cmath>
#define int long long

using namespace std;

inline string sub(string s, int idx) {
    string tmp = "";
    for(int i = idx; i < s.size();i++) {
        tmp += s[i];
    }
    return tmp;
}

inline bool check(string s) {
    int n = stoi(s);
    for(int i = 2;i <= sqrt(n);i++) {
        if(n % i == 0)  return false;
    }
    return true;
}

inline void solve() {
    string s;cin >> s;
    bool flag = true;
    for(int i = 0;i < s.size();i++) {
        if(!check(sub(s, i))) {
            flag = false;
        }
    }
    if(flag) {
        cout << s << " is a Prime Day!\n";
    }else {
        cout << s << " isn't a Prime Day!\n";
    }
    return ;
} 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int d;cin >> d;
    while(d--) {
        solve();
    }
    return 0;
}
