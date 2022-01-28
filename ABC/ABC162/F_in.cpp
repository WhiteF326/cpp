#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) ifs >> a[i];


#define minf -(1LL<<60)
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ifstream ifs("after_contest_02.txt");
  
  int n; ifs >> n;
  vector<ll> a(n);
  aryin(a, n);

  vector<vector<ll>> dp(n + 1, vector<ll>(4, minf));
  dp[1][0] = a[0];
  dp[2][1] = a[1];
  if(n % 2) dp[3][2] = a[2];

  for(int i = 1; i < n; i++){
    for(int j = 0; j < 3; j++){
      if(dp[i][j] == minf) continue;
      if(i + 2 <= n){
        dp[i + 2][j] = max(dp[i + 2][j], dp[i][j] + a[i + 1]);
      }
      if(i + 3 <= n){
        dp[i + 3][j + 1] = max(dp[i + 3][j + 1], dp[i][j] + a[i + 2]);
      }
    }
  }

  ll ans = minf;
  if(n % 2){
    for(int i = 0; i <= 2; i++){
      for(int j = 0; j <= 2 - i; j++){
        if(i || j) ans = max(ans, dp[n - i][j]);
      }
    }
  }else{
    ans = max(ans, dp[n - 1][0]);
    ans = max(ans, dp[n][0]);
    ans = max(ans, dp[n][1]);
  }

  cout << ans << endl;
}