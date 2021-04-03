#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
    return (x > 0) - (x < 0);
}

int main() {
    int n, a; cin >> n >> a;
    n = n % 500;
    cout << (n <= a ? "Yes" : "No") << endl;
}