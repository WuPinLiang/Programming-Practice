#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline int bs(int target) {
    int left = 0, right = 50;
    while(left <= right) {
        int mid = (left + right) / 2;
        int val = mid * (mid + 1) / 2;
        if(val == target) {
            return mid;
        }else if(val > target) 
            right = mid - 1;
        else 
            left = mid + 1;
    }
    // the while loop will terminate if and only if right < left ,
    // so we return right as our answer;
    return right ;
}

inline void solve() {
    int n; cin >> n;
    int ans = 0;
    for(int i = 2;i * i <= n;i++) {
        int cnt = 0;
        while(n % i == 0) {
            n = n / i;
            cnt++;
        }
        int mx = bs(cnt);
        ans += mx;
    }
    if(n > 1)
        ans++;
    cout << ans << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
