#include <iostream>
#include <vector>
#define int long long
#define inf 1000000007

using namespace std;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> psum(n + 1, 0);
    for(int i = 0;i < m;i++) {
        int a, b;cin >> a >> b;
        if(a > b) swap(a, b);
        psum[a]++;
        if(b + 1 <= n)    psum[b+1]--;
    }
    for(int i = 1;i <= n;i++) {
        psum[i] = psum[i-1] + psum[i];
    }
    int mx = 1, mn = 1;
    for(int i = 1;i <= n;i++) {
        //cout << psum[i] << ' ';
        if(psum[i] >= psum[mx])   mx = i;
        if(psum[i] < psum[mn])   mn = i;
    }
    cout << mn << ' ' << mx << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
