#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
#include <iostream>
#include <algorithm>
#include <vector>
#define int long long

using namespace std;

inline void solve() {
    int n, m;cin >> n >> m;
    vector<int> left(n + 1), right(n + 1);
    for(int i = 1;i <= n;i++) {
        left[i] = i - 1;
        right[i] = i + 1;
    }
    right[n] = 0;
    for(int i = 0;i < m;i++) {
        int num;cin >> num;
        if(left[num] == -1 and right[num] == -1) {
            cout << "我大意了啊~沒有閃\n";
            continue;
        }
        int t = right[num];
        if(t == 0) {   
            cout << "來~ 騙\n";
            continue;
        }
        t = right[t];
        if(t == 0) {
            cout << "來~ 騙\n";
            continue;
        }
        cout << t << '\n';
        
        if(left[t] != 0) right[left[t]] = right[t];
        if(right[t] != 0) left[right[t]] = left[t];
        right[t] = -1, left[t] = -1;
    }
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}