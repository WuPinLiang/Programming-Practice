#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define int long long 
#define lowbit(x) (x & (-x))
#define N 500005

using namespace std;

int bit[N];

inline int query(int idx) {
    int sum = 0;
    for(int i = idx;i > 0;i -= lowbit(i))
        sum += bit[i];
    return sum;
}

inline void update(int idx, int val) {
    for(int i = idx;i < N;i += lowbit(i)) {
        bit[i] += val;
    }
    return ;
}

inline void solve() {
    int n;cin >> n;
    map<int, vector<int> > mp;
    for(int i = 1;i <= 2 * n;i++) {
        int num;cin >> num;
        mp[num].push_back(i);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        ans += query(mp[i][1]) - query(mp[i][0]);
        update(mp[i][0], 1);
        update(mp[i][1], 1);
    }
    cout << ans << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}