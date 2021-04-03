#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main() {
    string s; cin >> s;
    if(s == "keyence"){
        cout << "YES" << endl; return 0;
    }
    for(int i = 1; i <= s.length() - 7; i++){
        for(int j = 0; j < s.length() - i; j++){
            string tmpstr = s;
            tmpstr.erase(j, i);
            if(tmpstr == "keyence"){
                cout << "YES" << endl; return 0;
            }
        }
    }
    cout << "NO" << endl;
}