#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
    return (x > 0) - (x < 0);
}

int main() {
    string s; cin >> s;
    int ans = 0;
    for(int i = 0; i < 4; i++){
        ans += s.substr(i, 1) == "+" ? 1 : -1;
    }
    cout << ans << endl;
}