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
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


#define mint modint998244353
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string s; cin >> s;
  int n = s.length();
  vector<int> digit(n, 0);
  for(int i = 0; i < n; i++) digit[i] = s[i] - '0';
  int m; cin >> m;
  vector<int> c(m);
  aryin(c, m);

  vector<vector<vector<mint>>> dp(n + 1, vector<vector<mint>>(2, vector<mint>(1024, 0)));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 1024; j++){
      // smaller = 0
      dp[i + 1][0][j | (1 << digit[i])] += dp[i][0][j] * 10 + digit[i];
      for(int d = 0; d < digit[i]; d++){
        dp[i + 1][1][j | (1 << d)] += dp[i][0][j] * 10 + d;
      }
      // smaller = 1
      for(int d = 0; d <= digit[i]; d++){
        dp[i + 1][1][j | (1 << d)] += dp[i][1][j] * 10 + d;
      }
    }
  }

  mint ans = 0;
  for(int i = 0; i < 1024; i++){
    bool flg = true;
    for(int j : c){
      if(i & (1 << j) == 0){
        flg = false;
      }
    }
    if(flg){
      ans += dp[n][0][i];
      ans += dp[n][1][i];
    }
  }

  cout << ans.val() << endl;
}