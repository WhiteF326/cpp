#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
    return (x > 0) - (x < 0);
}

int main() {
    int x, a, b; cin >> x >> a >> b;
    cout << (abs(x - a) < abs(x - b) ? "A" : "B") << endl;
}