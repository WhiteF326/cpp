#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    int a, b, w; cin >> a >> b >> w;
    w *= 1000;
    int mx = (int)floor(w / (double)a);
    int mn = (int)ceil(w / (double)b);
    if(mx < mn){
        cout << "UNSATISFIABLE" << endl;
    }else{
        cout << mn << " " << mx << endl;
    }
}