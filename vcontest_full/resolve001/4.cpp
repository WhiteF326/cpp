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
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


#define mint modint1000000007
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string lv; cin >> lv;
  int n = lv.length();
  vector<int> digits(n, 0);
  for(int i = 0; i < n; i++) digits[i] = lv[i] == '1';

  vector<vector<mint>> dp(n + 1, vector<mint>(2, 0));
  dp[0][0] = 1;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 2; j++){
      if(digits[i]){
        dp[i + 1][1] += dp[i][j];
      }else{
        dp[i + 1][j] += dp[i][j];
      }
      if(digits[i] || j){
        dp[i + 1][j] += dp[i][j] * 2;
      }
    }
  }

  cout << (dp[n][0] + dp[n][1]).val() << endl;
}
