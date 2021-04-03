#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main() {
    int n, m; cin >> n >> m;
    vector<int> s(m), c(m);
    for(int i = 0; i < m; i++){
        cin >> s[i] >> c[i];
        if(s[i] == 1 && c[i] == 0 && n != 1){
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i = (n == 1 ? 0 : (int)pow(10, n - 1)); i < (int)pow(10, n); i++){
        bool flg = true;
        for(int j = 0; j < m; j++){
            if((i / (int)pow(10, n - s[j])) % 10 != c[j]){
                flg = false;
            }
        }
        if(flg){cout << i << endl; return 0;}
    }
    cout << -1 << endl;
}