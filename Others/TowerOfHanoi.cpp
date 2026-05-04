#include <iostream>
#include <vector>
#define int long long

using namespace std;

int ans = 0;

inline void hanoi(int n, char from, char by, char to) {
    if(n == 0)
        return ;
    hanoi(n - 1, from, to, by);
    cout << "Move ring " << n << " from " << from << " to " << to << '\n';
    ans++;
    hanoi(n - 1, by, from, to);
    return ;
} 

inline void solve() {
    int n;cin >> n;
    hanoi(n, 'A', 'B', 'C');
    cout << ans << '\n';
    return ;   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}