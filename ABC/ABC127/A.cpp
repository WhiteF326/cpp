#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
    return (x > 0) - (x < 0);
}

int main() {
    int a, b; cin >> a >> b;
    if(a >= 13) cout << b << endl;
    else if(a >= 6) cout << b / 2 << endl;
    else cout << 0 << endl;
}