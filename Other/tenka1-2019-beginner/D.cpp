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


const ll modv = 998244353;

ll modpow(ll x, ll n, int mod){
  ll ret = 1;
  if(mod == 0){
    while(n > 0){
      if(n & 1) ret *= x;
      x *= x;
      n >>= 1;
    }
  }else{
    while(n > 0){
      if(n & 1) ret = ret * x % mod;
      x = x * x % mod;
      n >>= 1;
    }
  }
  return ret;
}

int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  vector<vector<int>> dp(n + 1, vector<int>(90001, modv));
  
  dp[0][0] = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= 90000; j++){
      dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
      if(j >= a[i]){
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - a[i]] + 1);
      }
    }
  }
  int lw = ceil(accumulate(all(a), 0) / 2.0);
  ll ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j < lw; j++){
      if(dp[i][j] == modv) continue;
      ans = (ans + modpow(2, n - i, modv) * dp[i][j]) % modv;
    }
  }
  ans + (ans + modv - 1) % modv;
  cout << ans << endl;
}