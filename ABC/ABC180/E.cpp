#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

#define infl INT_MAX

int main(){
  int n; cin >> n;
  vector<vector<int>> cty(n, vector<int>(3, 0));
  for(int i = 0; i < n; i++) cin >> cty[i][0] >> cty[i][1] >> cty[i][2];
  int bitx = 1 << (n + 1);

  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(bitx, vector<int>(n, infl)));
  dp[0][0][0] = 0;

  vector<int> bitlist(n);
  for(int i = 0; i < n; i++) bitlist[i] = 1 << i;
  auto costcal = [&](int from, int to){
    int ret = abs(cty[from][0] - cty[to][0])
            + abs(cty[from][1] - cty[to][1])
            + max(0, cty[to][2] - cty[from][2]);
    return ret;
  };

  for(int i = 0; i < n; i++){
    for(int j = 0; j < bitx; j++){
      for(int k = 0; k < n; k++){
        chmin(dp[i + 1][j][k], dp[i][j][k]);
        if(dp[i][j][k] != infl){
          for(int l = 0; l < n; l++){
            if(j & bitlist[l]) continue;
            int cost = costcal(k, l);
            chmin(dp[i + 1][j | bitlist[l]][l], dp[i][j][k] + cost);
          }
        }
      }
    }
  }
  
  cout << dp[n][(1 << n) - 1][0] << endl;
}