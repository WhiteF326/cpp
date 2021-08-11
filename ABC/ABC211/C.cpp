#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

constexpr int modv = 1000000007;

int main(){
  string s; cin >> s;
  int n = s.size();

  string mk = "chokudai";
  vector<vector<ll>> dp(n + 1, vector<ll>(9, 0));
  dp[0][0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= 8; j++){
      dp[i + 1][j] += dp[i][j];
      for(int k = 0; k < 8; k++){
        if(s[i] == mk[k] && j == k) dp[i + 1][j + 1] += dp[i][j];
      }
    }
    for(int j = 0; j <= 8; j++) dp[i + 1][j] %= modv;
  }
  cout << dp[n][8] << endl;
}