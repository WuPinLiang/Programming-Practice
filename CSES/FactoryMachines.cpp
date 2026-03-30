#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#include <iostream>
#include <vector>
#define int unsigned long long 
#define N 200005

using namespace std;

const int inf = 1e18;

vector<int> v(N);
int n, t;

inline bool check(int num) {
    int sum = 0;
    for(int i = 0;i < n;i++) {
        sum += (num / v[i]);
    }
    if(sum >= t)    return 1;
    return 0;
}

inline int bs(int left, int right) {
    int mn = inf;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(check(mid)) {
            right = mid - 1;
            mn = min(mn, mid);
        }else {
            left = mid + 1;
        }
    }
    return mn;
}

inline void solve() {
    cin >> n >> t;
    for(int i = 0;i < n;i++) {
        cin >> v[i];
    }
    cout << bs(1, 1e17) << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}