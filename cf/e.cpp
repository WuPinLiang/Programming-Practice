#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protecter")
#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline bool bigger(string a, string b) {
    if(a.size() != b.size()) {
        return false;
    }
    return a >= b;
}

inline void remove_zero(string& a) {
    int i = 0;
    while(i < a.size() and a[i] == '0') {
        i++;
    }
    string tmp = "";
    for(;i < a.size();i++) {
        tmp += a[i];
    }
    a = tmp;
    return ;
}

inline string subtract(string a, string b) {
    string ans = "";
    remove_zero(a);
    remove_zero(b);
    int i = a.size() - 1;
    int j = b.size() - 1;
    // a is bigger   cal (a - b)
    int borrow = 0;
    while(i >= 0) {
        int val_a = a[i] - '0';
        int val_b = b[j] - '0';
        int cur = val_a - val_b - borrow;
        if(cur < 0) {
            cur += 10;
            borrow = 1;
        }else {
            borrow = 0;
        }
        ans.push_back('0' + cur);
        i--, j--;
    }
    reverse(ans.begin(), ans.end());
    remove_zero(ans);
    return ans ;
}

inline string divide(string a, string b) {
    string remainder = "";

    for(int i = 0;i < a.size();i++) {
        remainder += a[i];
        remove_zero(remainder);
        while(!bigger(remainder, b)) {
            remainder = subtract(remainder, b);
        }
    }
    return remainder;
}

inline void solve() {
    string a, b;
    cin >> a >> b;
    cout << divide(a, b) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
