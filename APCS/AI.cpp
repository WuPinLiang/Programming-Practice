
#include <iostream>
#include <vector>
#define int long long
#define N 1000005

using namespace std;

// 修正：l, r, weight 大小擴展到 2*N，以涵蓋所有節點編號至 2n-1
vector<int> l(2 * N, -1), r(2 * N, -1), v(N), weight(2 * N, 0);

// 計算初始子樹總重
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

// 將貨物 num 沿輕邊下放，並更新路徑上所有節點的重量
inline int dfs(int cur, int num) {
    // 若為貨櫃(葉節點)，直接加重並回傳編號
    if (l[cur] == -1 && r[cur] == -1) {
        weight[cur] += num;
        return cur;
    }
    // 選擇較輕或左側(相等時)分支
    int next = (weight[l[cur]] <= weight[r[cur]] ? l[cur] : r[cur]);
    int res = dfs(next, num);
    // 回溯時更新當前分裝站重量
    weight[cur] += num;
    return res;
}

inline void solve() {
    int n, m;
    cin >> n >> m;
    // 修正：初始貨櫃編號從 n 到 2n-1
    for (int i = 0; i < n; i++) {
        cin >> weight[n + i];
    }
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    // 讀入分裝站的左右子節點
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        l[a] = b;
        r[a] = c;
    }

    init(1);

    // 輸出 m 個貨物進入的貨櫃編號，空格分隔
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
