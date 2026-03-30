#include <iostream>
#include <vector>
#include <set>
#include <map>
#define int long long
using namespace std;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for(int i = 0;i < m;i++)
        cin >> v[i];
    
    int ans = 0;
    map<int, int> mp;
    
    for(int i = 0;i < n - 1;i++) {
        mp[v[i]] ++;
    }
    
    for(int left = 1, right = n;left < m and left < right and  right < m;right++, left ++) { 
        if(mp.size() == n) {
            cout << left - 1 << ' ' << right - 1 << '\n';
            ans ++;
        } 
        mp[v[left - 1]] --;
        if(mp[v[left - 1]] == 0)  mp.erase(v[left] - 1);
        mp[v[right]]++;
      
    }
    cout << ans << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
