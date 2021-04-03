#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
    return (x > 0) - (x < 0);
}

int main() {
    vector<int> p(3);
    for(int i = 0; i < 3; i++) cin >> p[i];
    sort(p.begin(), p.end());
    cout << p[0] + p[1] << endl;
}