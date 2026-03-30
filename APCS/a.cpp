#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;
using pii = pair<int, int> ;

inline void solve() {
    int n;cin >> n;
    vector<vector<char> > v(n, vector<char> (n));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++)
            cin >> v[i][j];
    }

    vector<vector<int> > ans(n, vector<int> (n, 0));

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(v[i][j] == '*') {
                for(int x = 0;x < n;x++) {
                    ans[i][x] = 1;ans[x][j] = 1;
                }
            }
        }
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cout << ((ans[i][j] == 1) ? '*' : '0');
        }
        cout << '\n';
    }
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
