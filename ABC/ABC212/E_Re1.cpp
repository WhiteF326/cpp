#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)


#define mint modint998244353
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> g(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }

  vector<vector<mint>> dp(k + 1, vector<mint>(n, 0));
  dp[0][0] = 1;
  for(int i = 1; i <= k; i++){
    mint sum = 0;
    for(int j = 0; j < n; j++) sum += dp[i - 1][j];
    for(int j = 0; j < n; j++){
      dp[i][j] = sum - dp[i - 1][j];
      for(int k : g[j]){
        dp[i][j] -= dp[i - 1][k];
      }
    }
  }

  cout << dp[k][0].val() << endl;
}