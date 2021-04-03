#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    int x; cin >> x;
    int cnt = 0;
    while(true){
        cnt++;
        long long maxDist = cnt * (cnt + 1);
        if(maxDist >= 2 * x){
            cout << cnt << endl;
            break;
        }
    }
}