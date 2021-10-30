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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];

#define chmax(a, b) a = max(a, b)


int main(){
  // 選んだ個数も dp にもつ
  ll n, w; cin >> n >> w;
  vector<pair<ll, int>> v(n);
  for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
  ll lowest = v[0].first;
  for(int i = 0; i < n; i++) v[i].first -= lowest;

  // dp[i][j][k] = i 個目までで j 個選んで重さを k (+ lowest * j) にする場合の価値 max
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(3 * n + 1, -1)));
  dp[0][0][0] = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k <= 3 * n; k++){
        if(dp[i][j][k] == -1) continue;
        // 選ぶ
        chmax(dp[i + 1][j + 1][k + v[i].first], dp[i][j][k] + v[i].second);
        // 選ばない
        chmax(dp[i + 1][j][k], dp[i][j][k]);
      }
    }
  }
  // dp[n] のみを merge
  int ans = 0;
  for(int j = 0; j <= n; j++){
    for(int k = 0; k <= n * 3; k++){
      ll weight = lowest * j + k;
      if(weight > w) break;
      chmax(ans, dp[n][j][k]);
    }
  }
  cout << ans << endl;
}