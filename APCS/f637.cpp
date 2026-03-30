#include <iostream>
#include <vector>
#define inf 1000000007
#define int long long

using namespace std;

string s;
int idx = 0;

inline int solve(int n) {
    if(s[idx] == '2') {
        idx++;
        return solve(n / 2) + solve(n / 2) + solve(n / 2) + solve(n / 2);
    }
    else if(s[idx] == '1') {
        idx++;
        return n * n;
    }else if(s[idx] == '0') {
        idx++;
        return 0;
    }
    return inf;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int n;
    cin >> s >> n;

    cout << solve(n) << '\n';

    return 0;
}
