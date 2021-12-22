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
  string s; cin >> s;
  int n = s.length();
  vector<int> digits(n, 0);
  for(int i = 0; i < n; i++) digits[i] = s[i] - '0';
  int k; cin >> k;

  // i 桁目まで、smaller, 0 でない数字は k 桁
  vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(2, vector<ll>(k + 1, 0)));
  dp[0][0][0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= k; j++){
      // smaller でない
      if(digits[i] == 0){
        // 0 を選ぶしかない
        dp[i + 1][0][j] += dp[i][0][j];
      }else{
        // 0 を選ぶ
        dp[i + 1][1][j] += dp[i][0][j];
        if(j + 1 <= k){
          // 1 以上を選ぶ
          dp[i + 1][1][j + 1] += dp[i][0][j] * (digits[i] - 1);
          // digits[i] を選ぶ
          dp[i + 1][0][j + 1] += dp[i][0][j];
        }
      }
      // smaller である
      dp[i + 1][1][j] += dp[i][1][j];
      if(j + 1 <= k){
        dp[i + 1][1][j + 1] += dp[i][1][j] * 9;
      }
    }
  }

  cout << dp[n][0][k] + dp[n][1][k] << endl;
}