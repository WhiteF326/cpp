#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    int n; cin >> n;
    string s; cin >> s;
    if(n % 2){
        cout << "-1" << endl;
    }else{
        int ans = 0;
        string d = s.substr(0, n / 2);
        string e = s.substr(n / 2, n / 2);
        for(int i = 0; i < n / 2; i++){
            if(d.substr(i, 1) != e.substr(i, 1)) ans++;
        }
        cout << ans << endl;
    }
}