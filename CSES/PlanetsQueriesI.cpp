#include <iostream>
#include <vector>
#include <algorithm>
#define N 30

using namespace std;

vector<int> to_binary(int num) {
    vector<int> ans ;
    while(num > 0) {
        ans.push_back(num % 2);
        num /= 2;
    }
    //reverse(ans.begin(), ans.end());
    return ans ;
}

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    vector<vector<int> > dp(31, vector<int> (n + 1, 0));
    for(int i = 1;i <= n;i++)
        cin >> v[i];
    
    for(int i = 1;i <= n;i++) {
        dp[0][i] = v[i];
    }

    for(int j = 1;j <= 30;j++) {
        for(int i = 1;i <= n;i++) {
            dp[j][i] = dp[j-1][dp[j - 1][i]];
        }
    }

    for(int i = 0;i < m;i++) {
        int a, b;cin >> a >> b;
        // vector<int> mv = to_binary(b);
        /*
        for(int j = 0;j < mv.size();j++) {
            if(mv[j] == 1)
              a = dp[a][j];
        }*/
        for(int j = 0;j < 30;j++) {
            if(b & (1 << j))
                a = dp[j][a];
        }
        cout << a << '\n';
    }
    cout << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0 ;
}
