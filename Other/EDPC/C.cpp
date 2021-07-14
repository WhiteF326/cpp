#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
#define all(arr) arr.begin(), arr.end()
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<vector<int>> h(n, vector<int>(3));
  for(int i = 0; i < n; i++) for(int j = 0; j < 3; j++) cin >> h[i][j];

  vector<vector<int>> dp(n + 1, vector<int>(3, 0));
  dp[0] = {0, 0, 0}, dp[1] = h[0];

  for(int i = 2; i <= n; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        if(j == k) continue;
        // 前日jで当日kへ配る
        dp[i][k] = max(dp[i][k], dp[i - 1][j] + h[i - 1][k]);
      }
    }
  }

  cout << *max_element(all(dp[n])) << endl;
}