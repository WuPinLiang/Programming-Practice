#include <iostream>
#include <iostream>
#include <vector>
#define int long long
#define lc 2 * idx
#define rc 2 * idx + 1
#define N 200005
 
using namespace std;
 
struct Node {
    int left, right, tag, sum;
} seg[4 * N];
 
vector<int> v(N);
 
inline void build(int left, int right, int idx = 1) {
    seg[idx].left = left;
    seg[idx].right = right;
    seg[idx].tag = 0;
    if (left == right) {
        seg[idx].sum = v[left];
        return;
    }
    int mid = (left + right) / 2;
    build(left, mid, lc);
    build(mid + 1, right, rc);
    seg[idx].sum = seg[lc].sum + seg[rc].sum;
}
 
inline void push(int idx) {
    if (seg[idx].tag != 0) {
        int l = seg[idx].left;
        int r = seg[idx].right;
        int mid = (l + r) / 2;
        seg[lc].tag += seg[idx].tag;
        seg[lc].sum += seg[idx].tag * (mid - l + 1);
        seg[rc].tag += seg[idx].tag;
        seg[rc].sum += seg[idx].tag * (r - mid);
        seg[idx].tag = 0;
    }
}
 
inline void update(int left, int right, int ul, int ur, int val, int idx = 1) {
    if (ul > right || ur < left) return;
    if (ul <= left && right <= ur) {
        seg[idx].tag += val;
        seg[idx].sum += val * (right - left + 1);
        return;
    }
    push(idx);
    int mid = (left + right) / 2;
    update(left, mid, ul, ur, val, lc);
    update(mid + 1, right, ul, ur, val, rc);
    seg[idx].sum = seg[lc].sum + seg[rc].sum;
}
 
inline int query(int left, int right, int pos, int idx = 1) {
    if (left == right) return seg[idx].sum;
    push(idx);
    int mid = (left + right) / 2;
    if (pos <= mid)
        return query(left, mid, pos, lc);
    else
        return query(mid + 1, right, pos, rc);
}
 
inline void solve() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> v[i];
    build(1, n);
    while (q--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int left, right, val;
            cin >> left >> right >> val;
            update(1, n, left, right, val);
        } else {
            int pos;
            cin >> pos;
            cout << query(1, n, pos) << '\n';
        }
    }
}
 
signed main() {
    solve();
    return 0;
}
