#include <iostream>
#include <vector>
#include <map>
#define int long long
#define inf 1000000007
using namespace std;

inline void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0;i < n;i++)
        cin >> v[i];

    int left = 0, mx = -inf;

    map<int, int> mp;
    
    for(int right = 0;right < n;right++) {

        while(mp.count(v[right]) and left <= right) {
            mp[v[left]]--;
            if(mp[v[left]] == 0)  mp.erase(v[left]);
            left ++;
        }

        mp[v[right]]++;
        
        mx = max(mx, right - left + 1);
    }

    cout << mx << '\n';

    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
