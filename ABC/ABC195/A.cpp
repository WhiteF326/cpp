#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    int m, h; cin >> m >> h;
    if(h % m == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}