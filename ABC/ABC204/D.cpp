#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> t(n);
  for(int i = 0; i < n; i++) cin >> t[i];

  // isexist[i][j] = i個目までの料理で総和をjにする方法があるか
  int s = accumulate(t.begin(), t.end(), 0);
  int st = ceil(s / 2.0);

  vector<vector<bool>> dp(n + 1, vector<bool>(100001, false));
  dp[0][0] = true;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= st; j++){
      if(dp[i - 1][j]){
        // 選ぶ
        dp[i][j + t[i - 1]] = true;
        // 選ばない
        dp[i][j] = true;
      }
    }
  }
  int ans = INT_MAX;
  for(int i = s; i >= 0; i--){
    if(dp[n][i]){
      ans = min(ans, max((int)abs(s - i), i));
    }
  }
  cout << ans << endl;
}