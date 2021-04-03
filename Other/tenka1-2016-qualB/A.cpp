#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
    return (x > 0) - (x < 0);
}

double f(double n){
    return floor((pow(n, 2) + 4.0) / 8.0);
}
int main() {
    cout << f(f(f(20))) << endl;
}