#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    long long ans = 0;
    for(int i = 0; i < m - 1; i++){
        for(int j = i + 1; j < m; j++){
            long long sub = 0;
            for(int s = 0; s < n; s++){
                sub += max(a[s][i], a[s][j]);
            }
            ans = max(ans, sub);
        }
    }
    cout << ans << endl;
}