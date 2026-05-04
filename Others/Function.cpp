#include <iostream>
#include <vector>
#define int long long

using namespace std;

inline int f(), g(), h();

inline void solve() {
    string c;cin >> c;
    if(c == "f")
        cout << f() << '\n';
    else if(c == "g")
        cout << g() << '\n';
    else if(c == "h")
        cout << h() << '\n';
    else 
        cout << c << '\n';
    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();    
    return 0;
}

inline int f() {
    int x = 0;
    string s;cin >> s;
    if(s == "h")    x = h();
    else if(s == "g")    x = g();
    else if(s == "f")    x = f();
    else x = stoi(s);
    return 2 * x - 3; 
}

inline int g() {
    int x = 0, y = 0;
    string a;cin >> a;
    if(a == "h")    x = h();
    else if(a == "g")    x = g();
    else if(a == "f")    x = f();
    else x = stoi(a);
    
    string b;cin >> b;
    if(b == "h")    y = h();
    else if(b == "g")   y = g();
    else if(b == "f")   y = f();
    else y = stoi(b);

    return 2 * x + y - 7;
}

inline int h() {
    int x = 0, y = 0, z = 0;
    string a;cin >> a;
    if(a == "h")    x = h();
    else if(a == "g")    x = g();
    else if(a == "f")    x = f();
    else x = stoi(a);
    
    string b;cin >> b;
    if(b == "h")    y = h();
    else if(b == "g")   y = g();
    else if(b == "f")   y = f();
    else y = stoi(b);

    string c;cin >> c;
    if(c == "h")    z = h();
    else if(c == "g")   z = g();
    else if(c == "f")   z = f();
    else z = stoi(c);

    return 3 * x - 2 * y + z;
}
