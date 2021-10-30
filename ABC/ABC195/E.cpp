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

  string s; cin >> s;
  string x; cin >> x;

  // dp[i][j] = i 手目で値 % 7 = j
  vector<vector<bool>> dp(n + 1, vector<bool>(7, 0));
  dp[0][0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 7; j++){
      if(!dp[i][j]) continue;
      dp[i + 1][j] = dp[i + 1][j] | 1;
      dp[i + 1][(j * 10 + s[i] - '0') % 7] = dp[i + 1][(j * 10 + s[i] - '0') % 7] | 2;
    }
  }


}