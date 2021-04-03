#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    double a, b, x; cin >> a >> b >> x;

    cout << fixed << setprecision(10);
    if(a * a * b / 2.0 <= x){
        cout << 180.0 * atan(2.0 * (a * a * b - x) / a / a / a) / acos(-1) << endl;
    }else{
        cout << 180.0 * atan(a * b * b / 2.0 / x) / acos(-1) << endl;
    }
}