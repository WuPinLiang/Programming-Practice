#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline void solve() {
    int n;cin >> n;
    vector<vector<int> > v(n, vector<int> (n, 0));
    for(int i = 0;i < n;i++) {
        for(int j = i + 1;j < n;j++) {
            cin >> v[i][j];
        }
    }
    for(int i = 0;i < n;i++) {
        for(int j = i + 1;j < n;j++) {
            for(int k = j + 1;k < n;k++) {
                if(v[i][j] + v[j][k] < v[i][k]) {
                    cout << "Yes\n";
                    return ;
                } 
            }
        }
    }        
    cout << "No\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
