#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){

  vector<ll> fact(101, 1);
  for(int i = 1; i <= 100; i++){
    fact[i] = fact[i - 1] * i % modv;
  }

  ll n, x; cin >> n >> x;
  vector<ll> a(n);
  for(ll i = 0; i < n; i++) cin >> a[i];

  // dp[i][j][k] = Aiまででj個ちょうど選んでxor値をkにする通り数

  vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(511, 0)));
  dp[0][0][0] = 1;

  for(ll i = 1; i <= n; i++){
    for(ll j = 0; j <= i - 1; j++){
      for(ll k = 0; k <= 256; k++){
        dp[i][j][k] += dp[i - 1][j][k];
        dp[i][j][k] %= modv;
        dp[i][j + 1][k ^ a[i - 1]] += dp[i - 1][j][k];
        dp[i][j + 1][k ^ a[i - 1]] %= modv;
      }
    }
  }

  ll ans = 0;
  for(ll i = 0; i <= n; i++){
    ll fc = dp[n][i][x] * fact[i];
    ans += fc % modv;
    ans %= modv;
  }
  cout << ans << endl;
}
