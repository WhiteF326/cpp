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


#define mint modint998244353
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;
    s--, t--, x--;

    vector<vector<int>> g(n);
    query(m){
        int u, v; cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    
    // i 番目が j で、なおかつ頂点 X を d 回通っている
    vector<vector<vector<mint>>> dp(k + 1, vector<vector<mint>>(n, vector<mint>(2, 0)));

    dp[0][s][0] = 1;

    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            for(int d = 0; d < 2; d++){
                for(int v : g[j]){
                    if(v != x){
                        dp[i + 1][v][d] += dp[i][j][d];
                    }else{
                        dp[i + 1][v][(d + 1) % 2] += dp[i][j][d];
                    }
                }
            }
        }
    }

    cout << dp[k][t][0].val() << endl;
}
