#include <iostream>
#include <set>
#include <vector>
#define int long long
using namespace std;

string s, k;
int n;

set<string> all, ans;

string change(int l, int len) {
    string tmp = "";
    for(int i = 0;i < len;i++) {
        tmp += s[l + i];
    }
    return tmp;
}

inline void dfs(int depth, string cur) {
    if(depth == n) {
        //cout << cur << ' ';
        if(!all.count(cur)) ans.insert(cur);
        return ;
    }
    for(int i = 0;i < k.size();i++) {
        dfs(depth + 1, cur + k[i]);
    }
}

inline void solve() {

    cin >> k >> n >> s;
    
    for(int i = 0;i <= s.size() - n;i++) {
        all.insert(change(i, n));
    }

    dfs(0, "");

    cout << *ans.begin() << '\n';

    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
