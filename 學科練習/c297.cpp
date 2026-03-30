#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

inline void solve() {
    vector<vector<string> > v(9, vector<string>(5));
    vector<vector<int> > g(9, vector<int>(5));
    vector<int> p(9);
    for(int i = 0;i < 9;i++) {
        cin >> p[i];
        for(int j = 0;j < p[i];j++) {
            cin >> v[i][j];
            if(v[i][j] == "FO" or v[i][j] == "GO" or v[i][j] == "SO")
                g[i][j] = -1;
            else if(v[i][j] == "1B")
                g[i][j] = 1;
            else if(v[i][j] == "2B")
                g[i][j] = 2;
            else if(v[i][j] == "3B")
                g[i][j] = 3;
            else if(v[i][j] == "HR")
                g[i][j] = 4;
        }
    }
    int out;cin >> out;
    int cnt = 0, score = 0, tmp = 0;
    bool f = 0, s = 0, t = 0;
    int atbat = 0;
    vector<int> turn(9, 0);
    while(cnt < out) {
        int cur = g[atbat][turn[atbat] % p[atbat]];
        turn[atbat]++;
        if(cur == -1) {
            tmp++, cnt++;
            if(tmp == 3) {
                tmp = 0;
                f = s = t = 0;
            }
        }else if(cur == 1) {
            if(t) score++, t = 0;
            if(s) t = 1, s = 0;
            if(f) s = 1;
            f = 1;
        }else if(cur == 2) {
            if(t) score++, t = 0;
            if(s) score++, s = 0;
            if(f) t = 1, f = 0;
            s = 1;
        }else if(cur == 3) {
            if(t) score++, t = 0;
            if(s) score++, s = 0;
            if(f) score++, f = 0;
            t = 1;
        }else if(cur == 4) {
            if(t) score++, t = 0;
            if(s) score++, s = 0;
            if(f) score++, f = 0;
            score++;
        }
        atbat = (atbat + 1) % 9;
    }
    cout << score << '\n';
    return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
