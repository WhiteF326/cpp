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


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string s; cin >> s;
  int n = s.length();
  vector<int> digits(n, 0);
  for(int i = 0; i < n; i++) digits[i] = s[i] - '0';

  int k; cin >> k;

  vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(2, vector<ll>(4, 0)));
  dp[0][0][0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= 3; j++){
      if(digits[i] == 0){
        dp[i + 1][0][j] += dp[i][0][j];
      }else{
        dp[i + 1][1][j] += dp[i][0][j];
        if(j + 1 <= k){
          dp[i + 1][1][j + 1] += dp[i][0][j] * (digits[i] - 1);
          dp[i + 1][0][j + 1] += dp[i][0][j];
        }
      }

      dp[i + 1][1][j] += dp[i][1][j];
      if(j + 1 <= k){
        dp[i + 1][1][j + 1] += dp[i][1][j] * 9;
      }
    }
  }

  cout << dp[n][0][k] + dp[n][1][k] << endl;
}