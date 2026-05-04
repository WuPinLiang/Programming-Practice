#include <iostream>
#include <vector>
#include <map>
#define int long long 

using namespace std;

int n, ans = 0;

inline void dfs(int chess, int last_row, vector<int>& col, vector<int>& a, map<int, int>& b) {
    if(chess == n + 1) {  
        ans++;
        return ;
    }
    for(int i = last_row + 1;i <= 8;i++) {
        for(int j = 1;j <= 8;j++) {
            if(!col[j] and !a[i + j] and !b[i - j]) {
                col[j]++, a[i + j]++, b[i - j]++;
                dfs(chess + 1, i, col, a, b);
                col[j]--, a[i+j]--, b[i-j]--;
            }
        }
    }
    return ;
}

inline void solve() {
    cin >> n;
    vector<int> col(10, 0), a(20, 0);
    map<int, int> b;
    dfs(1, 0, col, a, b);
    cout << ans << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}