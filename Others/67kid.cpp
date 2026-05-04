#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

bool ans = false;
int a[5];

inline void dfs(int depth, int sum) {
    //cout << sum << ' ';
    if(depth == 5) {
        //cout << sum << ' ';
        if(sum == 67)
            ans = true;
        return ;
    }
    if(ans) return ;
    
    dfs(depth + 1, sum + a[depth]);
    dfs(depth + 1, sum - a[depth]);
    dfs(depth + 1, sum * a[depth]);
    return ;
}

inline void solve() {
    for(int i = 0;i < 5;i++) 
        cin >> a[i];
    sort(a, a + 5);
    do {
        dfs(1, a[0]);
        if(ans) break;
    }while(next_permutation(a, a + 5));
    cout << (ans ? "Possible\n" : "Impossible\n"); 
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}