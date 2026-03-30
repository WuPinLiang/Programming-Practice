#include <iostream>
#include <vector>

using namespace std;

signed main() {
    int t;cin >> t;
    while(t--) {
        int n;cin >> n;
        int sum = 0;
        for(int i = 0;i < n;i++) {
            int num;cin >> num;
            sum = sum xor num;
        }
        if(sum == 0) {
            cout << "second\n";
        }else 
            cout << "first\n";
    }
    return 0;
}
