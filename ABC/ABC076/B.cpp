#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    int a, b; cin >> a >> b;
    int ans = 1;
    for(int i = 0; i < a; i++){
        if(ans > b) ans += b;
        else ans += ans;
    }
    cout << ans << endl;
}