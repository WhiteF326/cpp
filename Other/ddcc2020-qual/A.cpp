#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
    return (x > 0) - (x < 0);
}

int main() {
    int x, y; cin >> x >> y;
    if(x == 1 && y == 1){
        cout << "1000000" << endl;
    }else{
        int ans = 0;
        switch(x){
        case 1:
            ans += 300000;
            break;
        case 2:
            ans += 200000;
            break;
        case 3:
            ans += 100000;
            break;
        default:
            break;
        }
        switch(y){
        case 1:
            ans += 300000;
            break;
        case 2:
            ans += 200000;
            break;
        case 3:
            ans += 100000;
            break;
        default:
            break;
        }
        cout << ans << endl;
    }
}