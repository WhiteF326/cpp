#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
    return (x > 0) - (x < 0);
}

int main() {
    string s; cin >> s;
    if(s == "RRR") cout << 3;
    else if(s == "RRS" || s == "SRR") cout << 2;
    else if(s == "SSS") cout << 0;
    else cout << 1;
    cout << endl;
}