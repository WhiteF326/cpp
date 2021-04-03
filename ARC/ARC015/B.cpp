#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main() {
    int n; cin >> n;
    int type[6] = {};
    for(int i = 0; i < n; i++){
        double x, m; cin >> x >> m;
        if(x >= 35) type[0]++;
        if(x >= 30 && x < 35) type[1]++;
        if(x >= 25 && x < 30) type[2]++;
        if(m >= 25) type[3]++;
        if(x >= 0 && m < 0) type[4]++;
        if(x < 0) type[5]++;
    }
    for(int i = 0; i < 5; i++) cout << type[i] << " ";
    cout << type[5] << endl;
}