#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    long long a, b; cin >> a >> b;
    long long x; cin >> x;
    // nの増加に従ってxは単調増加する
    long long l = 1, h = pow(10, 9), m = (l + h) / 2;
    while(l < h){
        long long tc = a * m + b * (long long)ceil(log10(m + 1));
        if(tc < x) l = m + 1;
        else if(tc > x) h = m - 1;
        else break;
        m = (l + h) / 2;
    }
    if(a * m + b * (long long)ceil(log10(m + 1)) > x) m--;
    cout << m << endl; return 0;
}
