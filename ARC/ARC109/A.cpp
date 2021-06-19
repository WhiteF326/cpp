#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

int main(){
  int a, b, x, y; cin >> a >> b >> x >> y;
  // dp[0, 1][i] = 0->A, 1->Bのi階へ移動するための最短時間
  vector<vector<int>> dp(2, vector<int>(100, INT_MAX));
  a--, b--;
  dp[0][a] = 0;
  for(int i = 0; i < 1000; i++){
    for(int j = 0; j <= 1; j++){
      for(int k = 0; k < 100; k++){
        if(dp[j][k] != INT_MAX){
          // 廊下
          chmin(dp[(j + 1) % 2][k], dp[j][k] + x);
          if(k - 1 >= 0 && j == 0){
            chmin(dp[1][k - 1], dp[0][k] + x);
          }
          if(k + 1 < 100 && j == 1){
            chmin(dp[0][k + 1], dp[1][k] + x);
          }
          // 階段
          if(k + 1 < 100){
            chmin(dp[j][k + 1], dp[j][k] + y);
          }
          if(k - 1 >= 0){
            chmin(dp[j][k - 1], dp[j][k] + y);
          }
        }
      }
    }
  }
  cout << dp[1][b] << endl;
}