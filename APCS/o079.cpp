#include <iostream>
#include <vector>
#include <map>
#define int long long

using namespace std;

inline void solve() {
    int n, k;cin >> n;
    vector<int> v(n + 1), prefix(n + 1), suffix(n + 1);
    vector<int> arr(n + 1);// odd -> 1 ,even -> 0.
    for(int i = 1;i <= n;i++) {
        cin >> v[i];
        arr[i] = (v[i] % 2);
        prefix[i] = prefix[i - 1] +  v[i];
    }
    

    return 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
