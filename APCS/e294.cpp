#include <iostream>
#include <vector>
#define int long long 
#define inf 1000000007
using namespace std;

vector<int> digit;
int ans = -inf;

inline void dfs(int depth, int tmp, bool is_same) {
    if(depth == -1) {
        ans = max(ans, tmp);
        return ;
    }
    for(int i = 1;i <= 9;i += 2) {
        if(i > digit[depth] and is_same) {
            continue;
        }
        bool cur = (is_same and i == digit[depth]) ? true : false;
        dfs(depth - 1, tmp * 10 + i, cur);
    }
}

inline void solve(int n) {
    int tmp = n;
    while(tmp > 0) {
        digit.push_back(tmp % 10);
        tmp /= 10;
    }
    dfs(digit.size() - 1, 0, 1);
    cout << (n - ans) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    while(cin >> n) {
        digit.clear();
        ans = -inf;
        solve(n);
    }
    return 0;
}
