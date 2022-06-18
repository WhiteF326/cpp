#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#define print(x) cout << x << endl;
#define printarray(x) for(auto v : x) cout << v << " "; cout << endl;
#endif
#ifndef _DEBUG
#define print(x) 42;
#define printarray(x) 42;
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int dpow(int n, int k){
    int res = 1;
    while(k){
        if(k & 1) res *= n;
        n *= n;
        k >>= 1;
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int v; cin >> v;
            a[i][j] = v;
            a[j][i] = v;
        }
    }

    int ans = INT_MIN;
    for(int st = 0; st < dpow(3, n); st++){
        vector<vector<int>> grp(3);
        for(int i = 0; i < n; i++){
            grp[(st / dpow(3, i)) % 3].push_back(i);
        }
        int res = 0;
        for(int i = 0; i < 3; i++){
            for(int x : grp[i]){
                for(int y : grp[i]){
                    res += a[x][y];
                }
            }
        }
        chmax(ans, res / 2);
    }
    cout << ans << endl;
}
