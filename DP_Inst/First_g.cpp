#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main(){
  // n 個の品物(items に価値を格納) から任意の個数選ぶ
  // 価値の総和が k を超えないうちで最高になるような組み合わせにおける、価値の総和を答える

  int n; cin >> n;
  int k; cin >> k;
  vector<int> items(n, 0);
  for(int i = 0; i < n; i++) cin >> items[i];

  constexpr int limit = 100000;

  vector<vector<bool>> dp(n + 1, vector<bool>(limit + 1, false));
  dp[0][0] = true;

  for(int i = 1; i <= n; i++){
    for(int j = items[i - 1]; j <= limit; j++){
      if(dp[i - 1][j - items[i - 1]]){
        // i 番目の品物を選ぶ場合
        dp[i][j] = true;
        // 選ばない場合
        dp[i][j - items[i - 1]] = true;
      }
    }
  }

  int ans = 0;
  for(int i = 0; i <= k; i++){
      if(dp[n][i]) ans = i;
  }
  cout << ans << endl;
}