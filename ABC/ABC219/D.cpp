#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

#define chmin(a, b) a = min(a, b)

#define infl 100000

int main(){
  int n; cin >> n;
  int x, y; cin >> x >> y;
  vector<pair<int, int>> ab(n);
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    ab[i] = mp(a, b);
  }

  auto lim = [](int x){
    if(x < 300) return x;
    else return 300;
  };

  // i, x, y
  vector<vector<vector<int>>> dp(n + 1,
    vector<vector<int>>(301,
      vector<int>(301, infl)));
  dp[0][0][0] = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j <= 300; j++){
      for(int k = 0; k <= 300; k++){
        if(dp[i][j][k] == infl) continue;
        // 選ばない
        chmin(dp[i + 1][j][k], dp[i][j][k]);
        // 選ぶ
        chmin(dp[i + 1][lim(j + ab[i].first)][lim(k + ab[i].second)], dp[i][j][k] + 1);
      }
    }
  }

  int ans = infl;
  for(int i = x; i <= 300; i++){
    for(int j = y; j <= 300; j++){
      chmin(ans, dp[n][i][j]);
    }
  }
  cout << (ans == infl ? "-1" : to_string(ans)) << endl;
}