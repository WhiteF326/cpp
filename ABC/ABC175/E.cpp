#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define all(x) x.begin(), x.end()
using ll = long long;
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)


int main(){
  int sr, sc, k; cin >> sr >> sc >> k;
  
  vector<vector<ll>> stg(sr, vector<ll>(sc, 0));
  for(int i = 0; i < k; i++){
    int r, c, v; cin >> r >> c >> v;
    r--, c--;
    stg[r][c] = v;
  }

  vector<vector<vector<ll>>> dp(sr, vector<vector<ll>>(sc, vector<ll>(4, 0)));
  for(int i = 0; i < sr; i++){
    for(int j = 0; j < sc; j++){
      for(int k = 0; k <= 3; k++){
        // 足元にアイテムがある
        if(stg[i][j]){
          // 右
          if(j + 1 < sc && k <= 2){
            chmax(dp[i][j + 1][k + 1], dp[i][j][k] + stg[i][j]);
          }
          // 下
          if(i + 1 < sr && k <= 2){
            chmax(dp[i + 1][j][0], dp[i][j][k] + stg[i][j]);
          }
        }
        // 足元にアイテムが無いか、拾わない
        // 右
        if(j + 1 < sc){
          chmax(dp[i][j + 1][k], dp[i][j][k]);
        }
        // 下
        if(i + 1 < sr){
          chmax(dp[i + 1][j][0], dp[i][j][k]);
        }
      }
    }
  }

  // todo 最後のマスにアイテムがある場合の処理
  ll ans = 0;
  for(int i = 0; i <= 2; i++){
    chmax(ans, dp[sr - 1][sc - 1][i] + stg[sr - 1][sc - 1]);
  }
  chmax(ans, dp[sr - 1][sc - 1][3]);

  cout << ans << endl;
}