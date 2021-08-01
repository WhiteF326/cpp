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
  int n; cin >> n;
  string s; cin >> s;

  string mk = "atcoder";
  vector<vector<ll>> dp(n + 1, vector<ll>(8, 0));
  dp[0][0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= 7; j++){
      dp[i + 1][j] += dp[i][j];
      for(int k = 0; k < 7; k++){
        if(s[i] == mk[k] && j == k) dp[i + 1][j + 1] += dp[i][j];
      }
    }
    for(int j = 0; j <= 7; j++) dp[i + 1][j] %= modv;
  }
  cout << dp[n][7] << endl;
}