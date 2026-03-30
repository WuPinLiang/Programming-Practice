#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define int long long

using namespace std;

int n, q;
int block_size;
int dist;
vector<int> v, freq, ans;

struct query {
    int left, right, idx;
    bool operator < (const query& other) const {
        int block_a = left / block_size;
        int block_b = other.left / block_size;
        if (block_a == block_b)
            return right < other.right;
        return block_a < block_b;
    }
};

inline void add(int num) {
    if (++freq[num] == 1) dist++;
}

inline void remove(int num) {
    if (--freq[num] == 0) dist--;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> comp = v;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int i = 0; i < n; i++)
        v[i] = lower_bound(comp.begin(), comp.end(), v[i]) - comp.begin();

    block_size = sqrt(n);
    vector<query> Q(q);
    for (int i = 0; i < q; i++) {
        cin >> Q[i].left >> Q[i].right;
        Q[i].left--, Q[i].right--;
        Q[i].idx = i;
    }

    sort(Q.begin(), Q.end());

    freq.assign(comp.size(), 0);
    ans.assign(q, 0);
    dist = 0;
    int cur_l = 0, cur_r = -1;

    for (auto &tmp : Q) {
        int L = tmp.left, R = tmp.right, id = tmp.idx;
        while (cur_r < R) add(v[++cur_r]);
        while (cur_r > R) remove(v[cur_r--]);
        while (cur_l < L) remove(v[cur_l++]);
        while (cur_l > L) add(v[--cur_l]);
        ans[id] = dist;
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';

    return 0;
}
