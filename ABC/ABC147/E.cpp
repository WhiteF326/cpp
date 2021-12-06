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
  int h, w; cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w, 0));
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++) cin >> a[i][j];
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      int b; cin >> b;
      a[i][j] = abs(a[i][j] - b);
    }
  }

  vector<vector<vector<bool>>> dp(h, vector<vector<bool>>(w, vector<bool>(12801, 0)));
  dp[0][0][abs(a[0][0])] = true;

  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      // 右へ
      if(j + 1 < w){
        for(int k = 0; k <= 12800; k++){
          if(!dp[i][j][k]) continue;
          dp[i][j + 1][k + a[i][j + 1]] = true;
          dp[i][j + 1][abs(k - a[i][j + 1])] = true;
        }
      }
      // 下へ
      if(i + 1 < h){
        for(int k = 0; k <= 12800; k++){
          if(!dp[i][j][k]) continue;
          dp[i + 1][j][k + a[i + 1][j]] = true;
          dp[i + 1][j][abs(k - a[i + 1][j])] = true;
        }
      }
    }
  }

  int ans = INT_MAX;
  for(int i = 12800; i >= 0; i--){
    if(dp[h - 1][w - 1][i]){
      ans = min(ans, i);
    }
  }

  cout << ans << endl;
}