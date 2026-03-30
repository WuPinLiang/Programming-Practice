#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline bool check(int num) {
    if(num < 2)
        return false;
    for(int i = 2;i * i <= num;i++) {
        if(num % i == 0)
            return false;
    }
    return true ;
}

inline void solve() {
    string s;getline(cin, s);
    int mx = 0;
    for(int i = 0;i + 2 < s.size();i++) {
        int tmp = stoi(s.substr(i, 3));
        if(check(tmp)) {
            mx = max(mx, tmp);
        }
    }

    for(int i = 0;i + 1 < s.size();i++) {
        int tmp = stoi(s.substr(i, 2));
        if(check(tmp)) {
            mx = max(mx, tmp);
        }
    }

    for(int i = 0;i < s.size();i++) {
        int tmp = stoi(s.substr(i, 1));
        if(check(tmp)) {
            mx = max(mx, tmp);
        }
    }
    
    cout << mx << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}