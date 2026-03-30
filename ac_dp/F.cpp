#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector")
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

inline void solve() {
    string s, t;
    cin >> s >> t;
    int x = s.size();
    int y = t.size();
    vector<vector<int> > dp(x + 1, vector<int> (y + 1, 0));
    for(int i = 1;i <= x;i++) {
        for(int j = 1;j <= y;j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    int i = x, j = y;
    string lcs = "";
    while(i > 0 and j > 0) {
        if(s[i-1] == t[j-1]) {
            lcs += s[i-1];
            i--, j--;
        }else if(dp[i-1][j] > dp[i][j-1]) {
            //lcs += s[i-1];
            i--;
        }else {
            //lcs += t[j-1];
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}