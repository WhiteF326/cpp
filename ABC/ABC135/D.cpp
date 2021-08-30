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

#define ml modint1000000007

int main(){
  string s; cin >> s;
  int n = s.size();

  auto parse = [](char c){
    if(c == '?') return -1;
    else return c - '0';
  };

  // dp[i][mod 13]
  vector<vector<ml>> dp(n + 1, vector<ml>(13, 0));
  dp[0][0] = 1;

  vector<int> digm(n, 1);
  for(int i = n - 1; i > 0; i--){
    digm[i - 1] = (digm[i] * 10) % 13;
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < 13; j++){
      if(parse(s[i]) == -1){
        // any
        for(int d = 0; d <= 9; d++){
          dp[i + 1][(j + digm[i] * d) % 13] += dp[i][j];
        }
      }else{
        // defined
        dp[i + 1][(j + digm[i] * parse(s[i])) % 13] += dp[i][j];
      }
    }
  }

  cout << dp[n][5].val() << endl;
}