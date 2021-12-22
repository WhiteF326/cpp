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


int main(){
  ll n, k; cin >> n >> k;
  vector<ll> ans = {0, 0, 0};

  // calc parameter sum
  vector<vector<ll>> dp(4, vector<ll>(n * 3 + 1, 0));
  dp[0][0] = 1;

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < n * 3; j++){
      if(dp[i][j]){
        dp[i + 1][j + 1] += dp[i][j];
        if(j + n + 1 <= n * 3) dp[i + 1][j + n + 1] -= dp[i][j];
      }
    }
    for(int j = 1; j <= n * 3; j++) dp[i + 1][j] += dp[i + 1][j - 1];
  }

  vector<ll> lsum(all(dp[3]));
  for(int i = 1; i <= 3 * n; i++) lsum[i] += lsum[i - 1];

  // parameter sum
  ll ps = lower_bound(all(lsum), k) - lsum.begin();

  ll lf = k - *(--lower_bound(all(lsum), k)) - 1;
  // calc p1
  for(int i = 1; i <= n; i++){
    ll bs = dp[2][ps - i];
    if(bs > lf){
      ans[0] = i;
      break;
    }else{
      lf -= bs;
    }
  }
  ps -= ans[0];
  
  // calc p2
  for(int i = 1; i <= n; i++){
    ll bs = dp[1][ps - i];
    // cout << bs << endl;
    if(bs > lf){
      ans[1] = i;
      break;
    }else{
      lf -= bs;
    }
  }
  ps -= ans[1];
  ans[2] = ps;

  for(int i = 0; i < 3; i++) cout << ans[i] << " ";
  cout << endl;
}