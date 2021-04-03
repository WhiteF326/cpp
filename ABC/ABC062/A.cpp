#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
    return (x > 0) -(x < 0);
}

int main() {
    unordered_map<int, int> grp;
    //これ各月の最終日じゃん
    grp[1] = 0;
    grp[2] = 2;
    grp[3] = 0;
    grp[4] = 1;
    grp[5] = 0;
    grp[6] = 1;
    grp[7] = 0;
    grp[8] = 0;
    grp[9] = 1;
    grp[10] = 0;
    grp[11] = 1;
    grp[12] = 0;
    int x, y; cin >> x >> y;
    cout << (grp[x] == grp[y] ? "Yes" : "No") << endl;
}