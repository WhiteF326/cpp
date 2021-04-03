#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    int n, m; cin >> n >> m;
    vector<int> k(m);
    vector<vector<int>> s(m, vector<int>(0));
    for(int i = 0; i < m; i++){
        cin >> k[i];
        for(int j = 0; j < k[i]; j++){
            int x; cin >> x;
            s[i].push_back(x);
        }
    }
    vector<int> p(m);
    for(int i = 0; i < m; i++) cin >> p[i];
    int ans = 0;
    for(int i = 0; i < (int)pow(2, n); i++){
        bool flg = true;
        for(int j = 0; j < m; j++){
            int res = 0;
            for(int l = 0; l < k[j]; l++){
                res += (i / (int)pow(2, s[j][l] - 1)) % 2;
            }
            if(res % 2 != p[j]) flg = false;
        }
        ans += (int)flg;
    }
    cout << ans << endl;
}