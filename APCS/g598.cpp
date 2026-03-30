#include <iostream>
#include <vector>
#define int long long
#define N 20005

using namespace std;

int n, m;
int pa[2 * N], sz[2 * N];

vector<int> ori(2 * N);

inline int fnd(int x) {
    if(x == pa[x])  return x;
    return pa[x] = fnd(pa[x]);
}

inline void unite(int x, int y) {
    int px = fnd(x), py = fnd(y);

    if(px == py)  return ;
    if(sz[px] > sz[py]) //  sz[px] < sz[py]
        swap(px, py);  
    pa[px] = py;
    sz[py] += sz[px];
    return ;
}

inline void init() {
     for(int i = 0;i < 2 * N;i++) {
        pa[i] = i;sz[i] = 1;
    }

    for(int i = 0;i < 2 * m;i += 2) {
        int a = ori[i], b = ori[i + 1];
        unite(a, b + n);
        unite(a + n, b);
    }
}

inline void solve() {

    cin >> n >> m;
    for(int i = 0;i < 2 * m;i++) {
        cin >> ori[i];
    }
    
    init();

    int p, k;
    cin >> p >> k;

    vector<int> ans ;

    for(int i = 1;i <= p;i++) {
          
        bool flag = true;
        for(int j = 0;j < k;j++) {

            int a, b;
            cin >> a >> b;
            
            if(fnd(a) == fnd(b))  flag = false;

            unite(a, b + n);
            unite(a + n, b);
        }
        
        if(!flag) {
            ans.push_back(i);
            init();
        }
    }

    //cout << ans.size();

    for(int i = 0;i < ans.size();i++) {
        cout << ans[i] << '\n';
    }

    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
