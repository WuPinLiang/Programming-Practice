
#include <iostream>
#include <vector>
#define int long long
#define N 1000005

using namespace std;

vector<int> l(2 * N, -1), r(2 * N, -1), v(N), weight(2 * N, 0);

inline void init(int cur) {
    if (l[cur] != -1) {
        init(l[cur]);
        weight[cur] += weight[l[cur]];
    }
    if (r[cur] != -1) {
        init(r[cur]);
        weight[cur] += weight[r[cur]];
    }
}

inline int dfs(int cur, int num) {
    if (l[cur] == -1 && r[cur] == -1) {
        weight[cur] += num;
        return cur;
    }
    int next = (weight[l[cur]] <= weight[r[cur]] ? l[cur] : r[cur]);
    int res = dfs(next, num);
    weight[cur] += num;
    return res;
}

inline void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> weight[n + i];
    }
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        l[a] = b;
        r[a] = c;
    }

    init(1);

    for (int i = 0; i < m; i++) {
        int res = dfs(1, v[i]);
        cout << res << (i + 1 < m ? ' ' : '\n');
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

