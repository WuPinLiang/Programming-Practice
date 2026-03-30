#include <iostream>
#include <vector>
#include <map>
#define int long long
#define N 200010
using namespace std;

struct Node {
    int val;
    Node(int _val = 0) {
        val = _val;
    }
}arr[4 * N];

int query(int L, int R, int qL, int qR, int idx = 1) {
    if(qL <= L and qR >= R) {
        return arr[idx].val;
    }  
    if(qL > R or qR < L)  return 0;
    
    int M = (L + R) / 2;

    int Lans = query(L, M, qL, qR, 2 * idx);
    int Rans = query(M + 1, R, qL, qR, 2 * idx + 1);

    return Lans + Rans;
}

void update(int L, int R, int pos, int val, int idx = 1) {
    if(L > pos or R < pos)  return ;
    
    if(L == R and L == pos) {
        arr[idx].val = val;
        return ;
    }
    
    int M = (L + R) / 2;

    update(L, M, pos, val, 2 * idx);
    update(M + 1, R, pos, val, 2 * idx + 1);

    arr[idx].val = arr[2 * idx].val + arr[2 * idx + 1].val;
    return ;
}

inline void solve() {
    int n;cin >> n;
    vector<int> v(2 * n + 1);
    map<int, vector<int> > mp;
    for(int i = 1;i <= 2 * n;i++) {
        cin >> v[i];
        mp[v[i]].push_back(i);
    }
    
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        int left = mp[i][0];
        int right = mp[i][1];
        
        ans += query(1, 2 * n, left, right);
        update(1, 2 * n, left, 1);
        update(1, 2 * n, right, 1);
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
