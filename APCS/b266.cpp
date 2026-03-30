#include <iostream>
#include <vector>
#define int long long
using namespace std;

int r, c, m;

inline void opt1(vector<vector<int> >& arr) {
    vector<vector<int> > tmp(15, vector<int>(15));
    for(int i = 0;i < r;i++) {
        for(int j = 0;j < c;j++) {
            tmp[i][j] = arr[j][i];
        }
    }
    arr = tmp;
    return ;
}

inline void opt2(vector<vector<int> >& arr) {
    swap(r, c);
    vector<vector<int> > tmp(15, vector<int> (15));
    for(int i = 0;i < r;i++)  {
        for(int j = 0;j < c;j++) {
            tmp[i][j] = arr[c - j - 1][i];
        }
    }
    arr = tmp;
    return ;
}

inline void solve() {
    cin >> r >> c >> m;
    vector<vector<int> > arr(15, vector<int> (15));
    for(int i = 0;i < r;i++) {
        for(int j = 0;j < c;j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 0;i < m;i++) {
        int opt;cin >> opt;
        if(opt == 0) {
             opt1(arr);
        } else{
            opt2(arr);
        }
    }

    cout << r << ' ' << c << '\n';

    for(int i = 0;i < r;i++) {
        for(int j = 0;j < c;j++) {
            cout << arr[i][j] << ' ';
        }cout << '\n';
    }
    return ;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
