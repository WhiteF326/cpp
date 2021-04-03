#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    int n, m; cin >> n >> m;
    double mx = m * 6.0;
    //12の剰余を求めてm/60をnに足してから30を掛ける
    double nx = ((n % 12) + (m / 60.0)) * 30.0;
    double ax = abs(mx - nx);
    cout << (ax > 180 ? 360.0 - ax : ax) << endl;
}
