#include <iostream>
using namespace std;
int f(int a, int b) {
    
    if(b == 0) {
        return 1;
        // a^0 = 1;
    }

    else if(b % 2 == 1) {
        return a * f(a, b - 1);
        // 把奇數先換成偶數，這樣比較好處理
    }
    
    else {
        int half = f(a, b / 2);
        return half * half;
    }
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << f(a, b) << '\n';
    return 0;  
}

