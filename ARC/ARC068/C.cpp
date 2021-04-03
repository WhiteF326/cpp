#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long x; cin >> x;
    long long ans = 0;
    if(x >= 11){
        ans += (x / 11) * 2;
    }
    x = x % 11;
    if(x > 6) ans += 2;
    else if(x >= 1) ans += 1;
    cout << ans << endl;
}