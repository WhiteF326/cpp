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


#define mint modint1000000007
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, k; cin >> n >> k;
    vector<int> a(n, 0);
    aryin(a, n);

    vector<vector<mint>> dp(n + 1, vector<mint>(k * 2 + 4, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j + a[i] + 1] -= dp[i][j];
        }

        for(int j = 1; j < 2 * k + 4; j++){
            dp[i + 1][j] += dp[i + 1][j - 1];
        }
    }

    cout << dp[n][k].val() << endl;
}
