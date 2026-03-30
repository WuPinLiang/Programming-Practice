#include <iostream>
#include <vector>
#include <queue>
#define int long long
#define inf 1000000007
#define N 60000
using namespace std;

vector<int> val(N, -1), delay(N, 0);
int mx = -inf;

inline int cal(int a, int op, int b) {
    if(op == 1) return (a and b);
    else if(op == 2)  return (a or b);
    else if(op == 3)  return (a xor b);
    return -1;
}

inline void solve() {
    int p, q, r, m;
    cin >> p >> q >> r >> m;
    
    for(int i = 1;i <= p;i++)   cin >> val[i];

    vector<int> port(N);
    for(int i = p + 1;i <= p + q;i++)   cin >> port[i];
    
    vector<int> adj[N], indeg(N, 0);
    for(int i = 1;i <= m;i++) {
        int a, b;
        cin >> a >> b;
        indeg[b]++;
        adj[a].push_back(b);
    }
    
    queue<int> que;
    for(int i = 1;i <= p;i++) {
        if(indeg[i] == 0) {
            que.push(i);
        }
    }
  
    while(!que.empty()) {
        int cur = que.front();
        que.pop();
        mx = max(mx, delay[cur]);
        for(int nxt : adj[cur]) {

            if(port[nxt] == 4) {//opposite of val[cur];
                val[nxt] = !val[cur];
            }
            else if(val[nxt] == -1) {
                val[nxt] = val[cur];
            }
            else {
                val[nxt] = cal(val[cur], port[nxt], val[nxt]);
            }
            
            delay[nxt] = max(delay[nxt], delay[cur] + 1);

            if(--indeg[nxt] == 0)
                que.push(nxt);
        }
    }

    cout << mx - 1 << '\n';  

    for(int i = p + q + 1;i <= p + q + r;i++) {
        cout << val[i] << ' '; 
    }
    cout << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
