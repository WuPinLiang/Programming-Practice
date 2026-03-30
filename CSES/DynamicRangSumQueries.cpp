#include <iostream>
#include <vector>
#include <cmath>
#define int long long 
#define N 200005
using namespace std;

int n, q;
int block_size;
vector<int> block_sum(N, 0), v(N);

inline void update(int idx, int val) {
    int block_cur = idx / block_size;
    block_sum[block_cur] += (val - v[idx]);
    v[idx] = val;
    return ;
}

inline int query(int left, int right) {
    
    int block_start = left / block_size;
    int block_end = right / block_size;

    int sum = 0;

    if(block_start == block_end)
        for(int i = left;i <= right;i++)
            sum += v[i];
    else {
        //處理左邊
        for(int i = left;i < (block_start + 1) * block_size;i++) 
           sum += v[i];
        //處理中間
        for(int i = block_start + 1;i < block_end;i++)
            sum += block_sum[i];
       //處理右邊
       for(int i = block_end * block_size;i <= right;i++) 
            sum += v[i];
    }
     
    return sum ;
}

inline void solve() {
    cin >> n >> q;
    block_size = sqrt(n);
    for(int i = 0;i < n;i++) {
        cin >> v[i];
        block_sum[i / block_size] += v[i];
    }
    for(int i = 0;i < q;i++) {
        int opt;cin >> opt;
        int a, b;cin >> a >> b;
        if(opt == 1) {
            a--;
            update(a, b);
        }else {
            a--, b--;
            cout << query(a, b) << '\n';
        }
    }
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
