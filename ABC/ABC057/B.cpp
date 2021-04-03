#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for(int i = 0; i < m; i++) cin >> c[i] >> d[i];
    for(int i = 0; i < n; i++){
        int ans = INT_MAX;
        vector<int> anslist(m);
        for(int j = 0; j < m; j++){
            anslist[j] = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            ans = min(ans, anslist[j]);
        }
        for(int j = 0; j < m; j++){
            if(anslist[j] == ans){cout << j + 1 << endl; break;}
        }
    }
}