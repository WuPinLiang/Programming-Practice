#include <iostream>
#include <vector>
#define int long long

using namespace std;

void solve() {

    return ;
}

signed main () {
  
  solve();
  return 0;
}
// 對於每一次修改，都做一次最小生成樹，最後在輸出第一個 > K 的是哪一個
// time : O(M alpha(n) * q) = O(M * q) -> TLE 
// 
// 紀錄哪一些邊會在最小生成樹上，如果
