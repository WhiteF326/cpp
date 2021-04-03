#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, w; cin >> n >> w;
  vector<long long> weight(n), value(n);
  long long ans = 0;
  for(int i = 0; i < n; i++) cin >> weight[i] >> value[i];
  vector<vector<long long>> dp(n + 1, vector<long long>(w + 1, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= w; j++) {
      if (j - weight[i] >= 0) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - weight[i]] + value[i]);
      }
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
    }
  }
  cout << dp[n][w] << endl;
}