#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    string s; cin >> s;
    //aが入るポイントは4箇所なのでビット全探索できる
    for(int i = 0; i < 16; i++){
        string c = (i / 8 ? "A" : "");
        c += "KIH"; c += ((i / 4) % 2 ? "A" : "");
        c += "B"; c += ((i / 2) % 2 ? "A" : "");
        c += "R"; c += (i % 2 ? "A" : "");
        if(s == c){cout << "YES" << endl; return 0;}
    }
    cout << "NO" << endl;
}