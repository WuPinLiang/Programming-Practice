#include <iostream>
#include <vector>
#include <string>
#define int long long
using namespace std;

vector<string> s;
vector<int> d, c, q;

inline vector<int> change(int base, int n) {
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        bool top = s[base][i] == '*';
        bool bot = s[base + 2][i] == '*';

        if (top) res[i] = 1;
        else if (bot) res[i] = 0;
        else if (i > 0) res[i] = res[i - 1];
        else res[i] = 0;
    }
    return res;
}

inline void solve() {
    s.resize(9);
    int n;
    for (int i = 0; i < 9; i++) {
        getline(cin, s[i]);
        while (!s[i].empty() && s[i].back() == '\r') {
            s[i].pop_back();
        }
        n = s[i].size();
    }
    d = change(0, n);
    c = change(3, n);
    q = change(6, n);
    vector<int> ans(n);
    int prev = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] == 1) prev = d[i];
        ans[i] = prev;
    }
    vector<int> diff;
    for (int i = 0; i < n; i++) {
        if (ans[i] != q[i]) diff.push_back(i + 1);
    }
    if (diff.empty()) cout << "PASS\n";
    else {
        cout << diff[0];
        for (int i = 1; i < diff.size(); i++) cout << ',' << diff[i];
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
