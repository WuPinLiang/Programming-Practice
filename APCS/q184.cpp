#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define N 200005
#define inf 1000000007

using namespace std;

vector<int> v(N), psum(N);

inline int cost(int l, int r) {
    int mid = (l + r) / 2;
    
    int sum = 0;
    /*
    for(int i = l; i <= mid;i++) {
        sum += (v[mid] - v[i]);
    }
    for(int j = mid + 1;j < r;j++) {
        sum += (v[i] - v[mid]);
    }
    */
    sum += (mid - l + 1) * v[mid];
    sum += -(psum[mid] - psum[l - 1]);
    sum += (r - mid) * (-v[mid]);
    sum += (psum[r] - psum[mid]);
    return sum ;
}

inline void solveK() {
    int ans = inf;
    for(int i = 0;i + k - 1 < n;i++) {
        ans = min(ans, cost(i, i + k - 1));   
    }
    return ans ;
}

inline void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0;i < n;i++)  cin >> v[i];
    sort(v.begin(), v.end());
    psum[0] = v[0];
    for(int i = 1;i < n;i++) {
        psum[i] = psum[i-1] + v[i];
    }
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
