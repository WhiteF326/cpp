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
#define chmin(a, b) a = min(a, b)


int main(){
  string s; cin >> s;
  int n = s.length();
  vector<int> d(n, 0);
  for(int i = 0; i < n; i++) d[i] = s[i] - '0';

  reverse(all(d));
  d.push_back(0);

  // dp[i][carry] digitdp
  vector<vector<int>> dp(n + 10, vector<int>(2, INT_MAX));
  dp[0][0] = accumulate(all(d), 0);
  for(int i = 0; i < n + 2; i++){
    for(int carry = 0; carry < 2; carry++){
      if(!i && carry) continue;
      if(carry){
        if(d[i] == 9){
          // 強制的に持ち上がる
          chmin(dp[i + 1][1], dp[i][carry] - d[i]);
        }else{
          chmin(dp[i + 1][1], dp[i][carry] + 9 - 2 * d[i]);
          chmin(dp[i + 1][0], dp[i][carry]);
        }
      }else{
        chmin(dp[i + 1][1], dp[i][carry] + 11 - 2 * d[i]);
        chmin(dp[i + 1][0], dp[i][carry]);
      }
    }
  }

  // for(int i = 0; i < n + 3; i++) cout << dp[i][0] << " ";
  // for(int i = 0; i < n + 3; i++) cout << dp[i][1] << " ";
  // cout << endl;

  cout << min(dp[n + 2][1], dp[n + 2][0]) << endl;
}