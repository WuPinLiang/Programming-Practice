#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int> (m, 0));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            cin >> v[i][j];
    }
    cout << "AND: ";
    for(int i = 0;i < m;i++) {
        int ans = v[0][i];
        for(int j = 1;j < n;j++) {
            ans = ans and v[j][i];
        }
        cout << ans << ' ';
    }
    cout << "\n OR: ";
    for(int i = 0;i < m;i++) {
        int ans = v[0][i];
        for(int j = 1;j < n;j++) {
            ans = ans or v[j][i];
        }
        cout << ans << ' ';
    }
    cout << "\nXOR: ";
   for(int i = 0;i < m;i++) {
        int ans = v[0][i];
        for(int j = 1;j < n;j++) {
            ans = ans xor v[j][i];
        }
        cout << ans << ' ';
    }
   cout << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
