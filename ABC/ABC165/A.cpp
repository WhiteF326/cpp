#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
    return (x > 0) - (x < 0);
}

int main() {
    int k, a, b; cin >> k >> a >> b;
    if(ceil(a / (double)k) > floor(b / (double)k)){
        cout << "NG" << endl;
    }else cout << "OK" << endl;
}