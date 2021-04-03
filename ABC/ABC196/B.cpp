#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
    return (x > 0) - (x < 0);
}

int main() {
    string x; cin >> x;
    for(int i = 0; i < x.length(); i++){
        if(x.substr(i, 1) != "."){
            cout << x.substr(i, 1);
        }else{
            cout << endl;
            return 0;
        }
    }
}