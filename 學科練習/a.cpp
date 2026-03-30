#include <iostream>
#include <vector>
#define int long long

using namespace std;

int n, m;

inline bool check(int num) {
    vector<int> sum;
    int tmp = num;
    while(tmp > 0) {
        int ret = tmp % 10;
        sum.push_back(ret);
        tmp = tmp / 10;
    }
    int pow = sum.size();
    //cout << pow << ' ';
    int ans = 0;
    for(int i = 0;i < sum.size();i++) {
        int ret = 1;
        for(int j = 0;j < pow;j++) {
            ret *= sum[i];
        }
        ans += ret;
    }
    return ans == num;
}

inline void solve() {
    for(int i = m;i >= n;i--) {
        if(check(i)) {
            cout << i << '\n';
            return ;
        }
    }
    cout << 0 << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(cin >> n >> m)
        solve();
    return 0;
}