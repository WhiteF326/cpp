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
#define chmin(a, b) a = min(a, b)

int main(){
  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  aryin(a, n); aryin(b, m);
  // dp[i][j] = modified LCS
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
  dp[0][0] = 0;
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= m; j++){
      // a を削除する
      if(i < n) chmin(dp[i + 1][j], dp[i][j] + 1);
      // b を削除する
      if(j < m) chmin(dp[i][j + 1], dp[i][j] + 1);
      // ai = bi ならば消さなくてよく、でなければ + 1 される
      if(i < n && j < m)chmin(dp[i + 1][j + 1], dp[i][j] + (a[i] != b[j]));
    }
  }

  cout << dp[n][m] << endl;
}