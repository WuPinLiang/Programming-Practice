#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define int long long

using namespace std;

int n;

inline void solve() {
    vector<int> v(n);
    for(int i = 0;i < n;i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    cout << "A=";
    if(n % 2 == 0) {
        int left = v[n / 2 - 1];
        int right = v[n / 2];
        set<int> st;
        for(int i = left;i <= right;i++)
            st.insert(i);
        bool first = true;
        for(auto num : st) {
            if(first) {
                cout << num;   
                first = false;
            }else{
                cout << "、" << num;
            }
        }
    }else
        cout << v[n / 2];
    cout << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(cin >> n) {
        solve();
    }
    return 0;
}