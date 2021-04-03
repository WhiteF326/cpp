#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
    return (x > 0) - (x < 0);
}

int main() {
    int a, b; cin >> a >> b;
    cout << (int)max(a + b, (int)max(a - b, a * b)) << endl;
}