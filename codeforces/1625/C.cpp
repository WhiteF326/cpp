#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, l, v; cin >> n >> l >> v;
  vector<ll> d(n);
  aryin(d, n);
  vector<ll> a(n);
  aryin(a, n);

  d.push_back(l);
  // i 番目まで、j 個飛ばした時
  vector<vector<ll>> dp(n + 2, vector<ll>(n + v, LLONG_MAX));
  dp[0][0] = (d[1] - d[0]) * a[0];
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j <= v; j++){
      if(dp[i][j] == LLONG_MAX) continue;
      chmin(dp[i + 1][j], dp[i][j] + (d[i + 2] - d[i + 1]) * a[i + 1]);
      ll cl = 0;
      for(int k = 0; k <= v - j; k++){
        if(i + k + 2 > n) break;
        cl += (d[i + k + 2] - d[i + k + 1]) * a[i];
        chmin(dp[i + k + 1][j + k + 1], dp[i][j] + cl);
      }
    }
  }

  ll ans = LLONG_MAX;
  for(int i = 0; i <= v; i++){
    chmin(ans, dp[n - 1][i]);
  }
  cout << ans << endl;
}