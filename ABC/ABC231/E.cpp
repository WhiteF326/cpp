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
  int n; cin >> n;

  ll x; cin >> x;

  vector<ll> a(n); aryin(a, n);
  reverse(all(a));
  vector<ll> us(n, 0);
  ll y = x;
  for(int i = 0; i < n; i++){
    us[i] = y / a[i];
    y %= a[i];
  }

  reverse(all(a));
  reverse(all(us));

  vector<vector<ll>> dp(n + 1, vector<ll>(2, LLONG_MAX));
  dp[0][0] = accumulate(all(us), 0LL);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < 2; j++){
      if(dp[i][j] == LLONG_MAX) continue;
      // add
      if(i + 1 < n){
        ll ret = (a[i + 1] / a[i]) - (us[i] + j);
        chmin(dp[i + 1][1], dp[i][j] + ret - us[i] - j + 1);
      }
      // save
      chmin(dp[i + 1][0], dp[i][j]);
    }
  }

  cout << min(dp[n][0], dp[n][1]) << endl;
}