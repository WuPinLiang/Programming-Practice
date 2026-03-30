#include <iostream>
#include <vector>
#include <stack>
#define int long long 

using namespace std;

int solve(bool cmp);
int cal();

int idx = 0;
string s;

inline int getnum() {
    int ans = 0;
    while(idx < s.size() and s[idx] >= '0' and s[idx] <= '9') {
        ans = ans * 10 + (s[idx] - '0');
        idx++;
    }
    return ans ;
}

inline int cal() {
    idx += 2;
    int mx = solve(0), mn = mx;
    
    while(s[idx] != ')') {
        idx++;
        int tmp = solve(0);
        mx = max(mx, tmp);
        mn = min(mn, tmp);
    }

    idx += 1;
    return mx - mn;
}

inline int solve(bool cmp) {
    int n;
    if(s[idx] >= '0' and s[idx] <= '9')
        n = getnum();

    else if(s[idx] == 'f') n = cal() ;
    
    if(cmp or s[idx] == ',' or s[idx] == ')') return n;

    while(idx < s.size()) {
        if(s[idx] == '+') {
            idx ++;
            int b = solve(1);
            n += b;
        }else if(s[idx] == '*') {
            idx++;
            int b = solve(0);
            n *= b;
        }

        if(s[idx] == ',' or s[idx] == ')')
            return n;
    }

    return n;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> s;
    cout << solve(0) << '\n';
    return 0;
}
