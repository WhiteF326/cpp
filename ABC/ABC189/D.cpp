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
  int n; cin >> n;
  vector<string> s(n);
  aryin(s, n);

  vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
  dp[0][0] = 1;
  dp[0][1] = 1;
  for(int i = 0; i < n; i++){
    if(s[i] == "OR"){
      // t
      dp[i + 1][1] += dp[i][0];
      dp[i + 1][1] += dp[i][1];
      // f
      dp[i + 1][0] += dp[i][0];
      dp[i + 1][1] += dp[i][1];
    }else{
      dp[i + 1][0] += dp[i][0];
      dp[i + 1][1] += dp[i][1];
      // f
      dp[i + 1][0] += dp[i][0];
      dp[i + 1][0] += dp[i][1];
    }
  }

  cout << dp[n][1] << endl;
}