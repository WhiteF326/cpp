#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;

const ll modv = 998244353;

int main(){
  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> g(n, vector<int>(0));
  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    u--, v--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  
  // 日, 都市
  vector<vector<ll>> dp(k + 1, vector<ll>(n, 0));
  dp[0][0] = 1;
  for(int i = 1; i <= k; i++){
    ll sum = 0;
    for(int j = 0; j < n; j++) sum += dp[i - 1][j];
    for(int j = 0; j < n; j++){
      dp[i][j] = sum - dp[i - 1][j];
      for(int k : g[j]){
        dp[i][j] -= dp[i - 1][k];
      }
      dp[i][j] %= modv;
    }
  }
  cout << dp[k][0] << endl;
}