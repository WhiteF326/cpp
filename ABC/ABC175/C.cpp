#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    long long x, k, d; cin >> x >> k >> d;
    x = (long long)abs(x);
    if((long long)floor(x / d) > k){
        cout << (long long)abs(x - k * d) << endl;
    }else{
        long long m = (long long)floor(abs(x) / d);
        x -= m * d;
        k -= m;
        if(k % 2){
            cout << abs(x - d) << endl;
        }else{
            cout << x << endl;
        }
    }
}