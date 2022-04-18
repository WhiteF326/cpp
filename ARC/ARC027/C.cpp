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


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x, y; cin >> x >> y;
    int n; cin >> n;
    vector<int> t(n);
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> t[i] >> c[i];

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(x + 1, vector<int>(x + y + 1, -1)));
    dp[0][0][0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= x; j++){
            for(int k = 0; k <= x + y; k++){
                if(dp[i][j][k] == -1) continue;
                chmax(dp[i + 1][j][k], dp[i][j][k]);

                if(t[i] + k > x + y) continue;
                if(j == x) continue;

                chmax(dp[i + 1][j + 1][k + t[i]], dp[i][j][k] + c[i]);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= x + y; j++){
            chmax(ans, dp[n][i][j]);
        }
    }

    cout << ans << endl;
}