#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
    return (x > 0) - (x < 0);
}

int main() {
    int n, r; cin >> n >> r;
    cout << r + 100 * (10 - (n < 10 ? n : 10)) << endl;
}