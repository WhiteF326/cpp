#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main() {
    int n; cin >> n;
    string r; cin >> r;
    int ans = 0;
    unordered_map<string, int> grd;
    grd["A"] = 4;
    grd["B"] = 3;
    grd["C"] = 2;
    grd["D"] = 1;
    grd["F"] = 0;
    for(int i = 0; i < n; i++) ans += grd[r.substr(i, 1)];
    cout << fixed << setprecision(14) << (ans / (double)n) << endl;
}