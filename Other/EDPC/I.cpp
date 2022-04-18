#ifdef _DEBUG
#define _GLIBCXX_DEBUG
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
    
    int n; cin >> n;
    // n / 2 + 1 枚以上が表であればよい
    // dp[i][j] = i 枚目までで j 枚表である確率
    vector<double> p(n);
    aryin(p, n);

    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i + 1][j + 1] += dp[i][j] * p[i];
            dp[i + 1][j] += dp[i][j] * (1 - p[i]);
        }
    }

    double ans = 0;
    for(int i = n / 2 + 1; i <= n; i++){
        ans += dp[n][i];
    }
    cout << fs(12) << ans << endl;
}
