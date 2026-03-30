#include <iostream>
#include <vector>
#define int long long
#define inf 1000000007
#define N 300005
using namespace std;

struct Node {
    int mn, mn_idx;
    
    Node(int _mn = inf, int _mn_idx = 0) {
        mn = _mn, mn_idx = _mn_idx;
    }
}arr[4 * N];

int n;

inline void build(vector<int>& v, int left, int right, int idx = 1) {
    if(left == right) {
        arr[idx] = Node(v[left], left);
        return ;
    }

    int mid = (left + right) / 2;
    build(v, left, mid, 2 * idx);
    build(v, mid + 1, right, 2 * idx + 1); 
    
    if(arr[2 * idx].mn < arr[2 * idx + 1].mn) {
        arr[idx].mn = arr[2 * idx].mn;
        arr[idx].mn_idx = arr[2 * idx].mn_idx;
    }else {
        arr[idx].mn = arr[2 * idx + 1].mn;
        arr[idx].mn_idx = arr[2 * idx + 1].mn_idx;
    }
    return ;
}

int query(vector<int>& v, int left, int right, int qL, int qR, int idx = 1) {
    if(right < qL or left > qR) {
        return -1 ;
    }
    else if(qL <= left and qR >= right) {
        return arr[idx].mn_idx;
    }
    
    int mid = (left + right) / 2;
    int lc = 2 * idx, rc = 2 * idx + 1;
    int l_ans = query(v, left, mid, qL, qR, lc);
    int r_ans = query(v, mid + 1, right, qL, qR, rc);
    
    if(l_ans == -1) return r_ans;
    if(r_ans == -1) return l_ans;

    if(v[l_ans] < v[r_ans]) {
        return l_ans;
    }return r_ans;
}

inline int sum(int left, int right, vector<int>& prefix) {
    if(left == 1) return prefix[right];
    return prefix[right] - prefix[left - 1];
}

inline int f(vector<int>& v, vector<int>& prefix, int left, int right) {
    if(left == right)
        return v[left];
    int m = query(v, 1, n, left, right);
    
    int l_ans = sum(left, m - 1, prefix);
    int r_ans = sum(m + 1, right, prefix);

    if(l_ans == r_ans) {
        return f(v, prefix, m + 1, right);
    }
    
    if(l_ans < r_ans) {
        return f(v, prefix, m + 1, right);
    }else 
        return f(v, prefix, left, m - 1);
}

inline void solve() {
    cin >> n;
    vector<int> v(n + 1), prefix(n+1);
    for(int i = 1;i <= n;i++) {
        cin >> v[i];
        prefix[i] = prefix[i - 1] + v[i];
    }
    build(v, 1, n);
    int ans = f(v, prefix, 1, n);
    cout << ans << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    solve();
    return 0;
}
