#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
    return (x > 0) - (x < 0);
}

int main() {
    int n; cin >> n;
    if(n > 999){
        cout << "ABD";
    }else{
        cout << "ABC";
    }
}