#include <iostream> 
#include <vector> 
#include <sstream> 
#define int long long
using namespace std;

string m;
vector<int> pixels;
vector<string> b;

inline void f() {
    b.clear();
    for (int i = 0; i < pixels.size(); i++) {
        string s = "";
        int tmp = pixels[i];
        while (tmp > 0) {
            s.push_back('0' + (tmp % 2));
            tmp /= 2;
        }
        reverse(s.begin(), s.end());
        while (s.size() < 8) s = '0' + s;
        b.push_back(s);
    }
}

inline int change(string s) {
    int ans = 0, base = 1;
    for (int i = 7; i >= 0; i--) {
        if (s[i] == '1') ans += base;
        base *= 2;
    }
    return ans;
}

inline void solve() {
    f();
    int idx = 0;
    for (int i = 0; i + 2 < pixels.size(); i += 3) {
        string R = b[i], G = b[i + 1], B = b[i + 2];
        if (R[6] != G[6] && idx < m.size()) R[7] = m[idx++];
        if (G[6] != B[6] && idx < m.size()) G[7] = m[idx++];
        if (B[6] != R[6] && idx < m.size()) B[7] = m[idx++];
        cout << change(R) << ' ' << change(G) << ' ' << change(B);
        if (i + 3 < pixels.size()) cout << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> m) {
        cin.ignore();
        string p;
        if (!getline(cin, p)) break;
        stringstream ss(p);
        int num;
        pixels.clear();
        while (ss >> num) pixels.push_back(num);
        solve();
    }
    return 0;
}
