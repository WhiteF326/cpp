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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    for(int i = 0; i < m; i++) dp[0][i + 1] = 1;
    for(int i = 0; i < n - 1; i++){
        for(int j = 1; j <= m; j++){
            for(int k = j; k <= m; k += j){
                dp[i + 1][k] += dp[i][j];
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            cout << dp[i][j] << " ";
        }cout << endl;
    }
}
