#include <iostream>
#include <vector>
#define int long long

using namespace std;

int n, q;
int pa[200005], sz[200005];

inline void init() {
    for(int i = 0;i <= n;i++) {
        pa[i] = i, sz[i] = 1;
    }
}

inline int fnd(int x) {
    if(pa[x] == x)
        return x;
    return pa[x] = fnd(pa[x]);
}

inline void unite(int x, int y) {
    int px = fnd(x), py = fnd(y);
    if(px == py) {
        return ;
    }
    if(sz[px] > sz[py]) 
        swap(px, py);
    // sz[px] <= sz[py]
    sz[py] += sz[px];
    pa[px] = py;
    return ;
}

inline void solve() {
    cin >> n >> q;
    init();
    for(int i = 0;i < q;i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 0) {
            unite(a, b);
        }else {
            if(fnd(a) == fnd(b))
                cout << 1 << '\n';
            else 
                cout << 0 << '\n';
        }
    }
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}