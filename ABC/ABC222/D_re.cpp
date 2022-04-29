#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#define print(x) cout << x << endl;
#define printarray(x) for(auto v : x) cout << v << " "; cout << endl;
#endif
#ifndef _DEBUG
#define print(x)
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define all(x) x.begin(), x.end()
#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


#define mint modint998244353
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n), b(n);
    aryin(a, n);
    aryin(b, n);

    mint dp[n + 1][3005];
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 3000; j++){
            // max(j, a[i]) ~ b[i] まで
            dp[i + 1][max(j, a[i])] += dp[i][j];
            dp[i + 1][b[i] + 1] -= dp[i][j];
        }
        // 累積和
        for(int j = 1; j <= 3000; j++){
            dp[i + 1][j] += dp[i + 1][j - 1];
        }
    }

    mint ans = 0;
    for(int i = 0; i <= 3000; i++) ans += dp[n][i];
    cout << ans.val() << endl;
}