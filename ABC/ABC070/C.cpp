#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    //全ての入力の最小公倍数
    int n; cin >> n;
    long long t = 0;
    cin >> t;
    for(int i = 0; i < n - 1; i++){
        long long x; cin >> x;
        t = lcm(t, x);
    }
    cout << t << endl;
}
