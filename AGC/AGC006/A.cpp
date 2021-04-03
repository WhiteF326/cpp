#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
    return (x > 0) - (x < 0);
}

int main() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    if(s == t){cout << n << endl; return 0;}
    //逆に一致する長さを減らす
    for(int i = n - 1; i >= 0; i--){
        if(s.substr(s.length() - 1 - i) == t.substr(0, i + 1)){
            cout << n * 2 - i - 1 << endl;
            return 0;
        }
    }
    cout << n * 2 << endl;
    return 0;
}