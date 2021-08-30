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

#define vvvi vector<vector<vector<int>>>
#define vvi vector<vector<int>>
#define vi vector<int>

int main(){
  string s; cin >> s;
  int n = s.size();
  int kl; cin >> kl;
  vector<int> parse(n);
  for(int i = 0; i < n; i++) parse[i] = s[i] - '0';

  // dp[i][smaller][j][allzero] = i桁目までで0以外がj回出現する(smaller = 未満flg)
  vector<vvvi> dp(n + 1, vvvi(2, vvi(kl + 2, vi(2, 0))));
  dp[0][0][0][1] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= kl; j++){
      for(int allzero = 0; allzero <= 1; allzero++){
        if(dp[i][0][j][allzero]){
          if(parse[i] == 0){
            // 0
            dp[i + 1][0][j][allzero] += dp[i][0][j][allzero];
          }else{
            // 0
            dp[i + 1][1][j][allzero] += dp[i][0][j][allzero];
            // 1 <= d < parse[i]
            for(int d = 1; d < parse[i]; d++){
              dp[i + 1][1][j + 1][0] += dp[i][0][j][allzero];
            }
            // parse[i]
            dp[i + 1][0][j + 1][0] += dp[i][0][j][allzero];
          }
        }
        if(dp[i][1][j][allzero]){
          // 0
          dp[i + 1][1][j][allzero] += dp[i][1][j][allzero];
          // 1 <= d <= 9
          for(int d = 1; d <= 9; d++){
            dp[i + 1][1][j + 1][0] += dp[i][1][j][allzero];
          }
        }
      }
    }
  }

  cout << dp[n][0][kl][0] + dp[n][1][kl][0] << endl;
}