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

int main(){
  int d; cin >> d;
  int g; cin >> g;
  g /= 100;
  vector<pair<int, int>> scores(11);
  for(int i = 0; i < d; i++){
    int p, c; cin >> p >> c;
    c /= 100;
    scores[i + 1] = mp(p, c);
  }

  // dp[i][j] = 100i点問題までで100j点を満たすための問題数
  vector<vector<int>> dp(d + 1, vector<int>(200001, INT_MAX));
  dp[0][0] = 0;
  for(int i = 1; i <= d; i++){
    for(int j = 0; j <= 200000; j++){
      if(dp[i - 1][j] == INT_MAX) continue;
      chmin(dp[i][j], dp[i - 1][j]);
      for(int k = 1; k < scores[i].first; k++){
        chmin(dp[i][j + k * i], dp[i - 1][j] + k);
      }
      chmin(dp[i][j + scores[i].second + i * scores[i].first], dp[i - 1][j] + scores[i].first);
    }
  }

  int ans = INT_MAX;
  for(int i = g; i <= 200000; i++) chmin(ans, dp[d][i]);
  cout << ans << endl;
}