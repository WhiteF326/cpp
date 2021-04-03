#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    long double a, b, c; cin >> a >> b >> c;
    if(c - a - b <= 0) cout << "No";
    else if(4LL * a * b < (c - a - b) * (c - a - b)){
        cout << "Yes";
    }else{
        cout << "No";
    }
    cout << endl;
}