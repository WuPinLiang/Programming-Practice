#pragma optimize("Ofast", "no-stack-protecter", "fast-math", "O3")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
#define mod 1000000007

using namespace std ;

string s;
int d;
vector<int> v;
int dp[10005][105][2];

inline int dfs(int pos, int sum, bool same) {
    sum = sum % d;
    //cerr << pos << ' ';
    if(pos == v.size()) {
        if(sum % d == 0) {
            return dp[pos][sum % d][same] = 1;
        }
        return 0;
    }
    if(dp[pos][sum % d][same] != -1) {
        return dp[pos][sum % d][same] % mod;
    }
    int ans = 0;
    for(int i = 0;i < 10;i++) {
        if(same and i > v[pos]) {
            continue ;
        }
        bool tmp_same = (same and (i == v[pos]));
        ans += (dfs(pos + 1, sum + i, tmp_same) % mod);
    }
    return dp[pos][sum % mod][same] = ans % mod;
}

inline void solve() {
    cin >> s >> d;
    memset(dp, -1, sizeof(dp));
    for(char c : s)
        v.push_back(c - '0');
    //reverse(v.begin(), v.end());
    cout << (dfs(0, 0, 1) - 1 + mod) % mod << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
