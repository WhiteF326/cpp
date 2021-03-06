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
    
    int n, m; cin >> n >> m;
    int k; cin >> k;
    mint dp[n + 1][k + 1] = {mint(0)};
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            for(int next = 1; next <= m; next++){
                if(j + next > k) break;
                dp[i + 1][j + next] += dp[i][j];
            }
        }
    }

    mint ans = 0;
    for(int i = 0; i <= k; i++) ans += dp[n][i];
    cout << ans.val() << endl;
}
