#include <iostream>
#include <vector>
#include <cstring>
#define int long long
#define mod 1000000007

using namespace std;

string s;
vector<int> digit;
int dp[100005][10][2];
int len;

inline int dfs(int depth, int last, bool same) {
    if(dp[depth][last][same] != -1) return dp[depth][last][same];
    if(depth == len) {
        return 1;
    }
    int ans = 0;
    for(int i = last; i < 10;i++) {
        if(same and i > digit[depth]) {
            continue;
        }
        bool tmp_same = (same and i == digit[depth]) ? true : false;
        ans = (ans + dfs(depth + 1, i, tmp_same)) % mod;
    }
    return dp[depth][last][same] = ans % mod;
}

inline void solve() {
    for(int i = 0;i < s.size();i++) {
        digit.push_back((int)s.at(i) - '0');
    }
    memset(dp, -1, sizeof(dp));
    len = digit.size();
    cout << (dfs(0, 0, 1) - 1) % mod<< '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(cin >> s) {
        digit.clear();
        solve();
    }
    return 0;
}
