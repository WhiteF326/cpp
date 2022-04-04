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
mint dp[10001][2][101];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string k; cin >> k;
    int n = (int)k.length();
    vector<int> d(n, 0);
    for(int i = 0; i < n; i++){
        d[i] = k[i] - '0';
    }
    int m; cin >> m;

    dp[0][1][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // smaller
            for(int nd = 0; nd <= 9; nd++){
                dp[i + 1][0][(j + nd) % m] += dp[i][0][j];
            }

            // not smaller
            for(int nd = 0; nd < d[i]; nd++){
                dp[i + 1][0][(j + nd) % m] += dp[i][1][j];
            }
            dp[i + 1][1][(j + d[i]) % m] += dp[i][1][j];
        }
        // for(int j = 0; j < m; j++){
        //     cout << (dp[i + 1][0][j]).val() << " ";
        // }cout << endl;
        // for(int j = 0; j < m; j++){
        //     cout << (dp[i + 1][1][j]).val() << " ";
        // }cout << endl;
    }

    cout << (dp[n][0][0] + dp[n][1][0] - 1).val() << endl;
}
