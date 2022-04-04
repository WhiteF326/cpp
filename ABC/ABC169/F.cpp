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


#define modv 998244353
#define mint modint998244353
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, s; cin >> n >> s;
    vector<int> a(n);
    aryin(a, n);

    vector<vector<mint>> dp(n + 1, vector<mint>(s + 1, 0));
    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= s; j++){
            dp[i + 1][j] += dp[i][j] * 2;
            if(j - a[i] >= 0) dp[i + 1][j] += dp[i][j - a[i]];
        }
    }

    cout << dp[n][s].val() << endl;
}
