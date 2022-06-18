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


#define modv 998244353
#define mint modint998244353
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m, k; cin >> n >> m >> k;
    // dp[i][j] = i 項目が j であるような数列の総数
    vector<vector<mint>> dp(n, vector<mint>(m + 2, 0));
    for(int i = 1; i <= m; i++){
        dp[0][i] = 1;
    }

    if(k == 0){
        // corner!!
        cout << mint(m).pow(n).val() << endl;
        return 0;
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 1; j <= m; j++){
            // 小さいほう
            if(j - k >= 1){
                dp[i + 1][1] += dp[i][j];
                dp[i + 1][j - k + 1] -= dp[i][j];
            }
            // 大きいほう
            if(j + k <= m){
                dp[i + 1][j + k] += dp[i][j];
                dp[i + 1][m + 1] -= dp[i][j];
            }
        }
        // 累積
        for(int j = 2; j <= m; j++) dp[i + 1][j] += dp[i + 1][j - 1];
    }

    mint ans = 0;
    for(int i = 1; i <= m; i++) ans += dp[n - 1][i];
    cout << ans.val() << endl;
}
