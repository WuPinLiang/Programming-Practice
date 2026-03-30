#include <iostream>
#include <vector>
#define int long long 
#define inf 1000000007

using namespace std ;

vector<vector<int> > dp(505, vector<int> (505, -1));

inline int f(int a, int b) {
    if(a > b)
        swap(a, b);
    if(dp[a][b] != -1)
        return dp[a][b];
    if(a == b)
        return 0;
    int mn = inf;
    for(int i = 1;i < a;i++) {
        int tmp = f(a - i, b) + f(i, b) + 1;
        mn = min(mn, tmp);
    }
    for(int i = 1;i < b;i++) {
        int tmp = f(a, b - i) + f(a, i) + 1;
        mn = min(mn, tmp);
    }
    return dp[a][b] = mn;
}

inline void solve() {
    int a, b;
    cin >> a >> b;
    cout << f(min(a, b), max(a, b)) << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
