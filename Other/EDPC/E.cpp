#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, w; cin >> n >> w;
  vector<long long> weight(n), value(n);
  long long ans = 0;
  for(int i = 0; i < n; i++) cin >> weight[i] >> value[i];
  vector<vector<long long>> dp(n + 1, vector<long long>(1000 * n + 1, 1LL<<60));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < 1000 * n + 1; j++) {
      if (j - value[i] >= 0) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - value[i]] + weight[i]);
      }
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
    }
  }
  for(int i = 0; i < 1000 * n + 1; i++){
    if(dp[n][i] <= w) ans = i;
  }
  cout << ans << endl;
}