#include <iostream>
#include <vector>
#define N 100005
#define inf 1000000007
#define int long long 
using namespace std;

vector<int> adj[N];
vector<string> s(N);
vector<char> c(N);

vector<vector<int> > dp(N, vector<int> (4, inf));
// 定義 dp[i][j] 以 i 為根的子樹且他的字母選 'A' + j 的時候的最小漢名距離

int root = 0, n, m, ans = 0;

inline int char2idx(char tmp) {
    if(tmp == 'A')  return 0;
    else if(tmp == 'U') return 1;
    else if(tmp == 'G') return 2;
    else if(tmp == 'C') return 3;
    //else if(tmp == '@') return 4;
    return -1;
}

inline void dfs(int cur ,int pa) {
    
    if(c[cur] == '@') {
        for(int i = 0;i < 4;i++) {
            dp[cur][i] = 0;
        }
    }

    else if(char2idx(c[cur]) != -1) {
        int idx = char2idx(c[cur]);
        for(int i = 0;i < 4;i++) {
            if(i == idx)
                dp[cur][i] = 0;
            else
                dp[cur][i] = inf;
        }
    }

    for(int nxt : adj[cur]) {
        if(nxt == pa)   continue;
        dfs(nxt, cur);
        
        for(int i = 0;i < 4;i++) {
            
            if(dp[cur][i] == inf) continue;
            int mi = inf;
            for(int j = 0;j < 4;j++) {
                mi = min(mi, dp[nxt][j] + ((i == j) ? 0 : 1));
            }
            dp[cur][i] += mi;
        }
    }
    return ;
}

inline void solve() {
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(a == b)  root = a;
        else {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cin >> s[a];
    }
    for(int i = 0;i < m;i++) {
        vector<char> tmp;
        for(int j = 0;j < n;j++) {
            tmp.push_back(s[j][i]);
        }
        c = tmp;
        
        dfs(root, -1);
        
        int mn = inf;
        for(int j = 0;j < 4;j++) {
            mn = min(mn, dp[root][j]);
        }
        //cout << mn << ' '; 
        ans += mn;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
