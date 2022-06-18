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
    // dp[i][a][b][c] = i 要素目で LIS が {a, b, c} であるもの
    mint dp[n + 1][m + 2][m + 2][m + 2] = {0};
    dp[0][m + 1][m + 1][m + 1] = 1;
    for(int i = 0; i < n; i++){
        for(int v1 = 1; v1 <= m + 1; v1++){
            for(int v2 = 1; v2 <= m + 1; v2++){
                for(int v3 = 1; v3 <= m + 1; v3++){
                    for(int d = 1; d <= m; d++){
                        if(v1 >= d) dp[i + 1][d][v2][v3] += dp[i][v1][v2][v3];
                        else if(v2 >= d) dp[i + 1][v1][d][v3] += dp[i][v1][v2][v3];
                        else if(v3 >= d) dp[i + 1][v1][v2][d] += dp[i][v1][v2][v3];
                    }
                }
            }
        }
    }

    mint ans = 0;
    for(int a = 1; a <= m; a++){
        for(int b = a + 1; b <= m; b++){
            for(int c = b + 1; c <= m; c++){
                ans += dp[n][a][b][c];
            }
        }
    }

    cout << ans.val() << endl;
}
