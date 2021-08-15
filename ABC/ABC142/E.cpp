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
  int n, m; cin >> n >> m;
  vector<pair<int, vector<int>>> keys(m, pair<int, vector<int>>());
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    keys[i].first = a;
    for(int j = 0; j < b; j++){
      int c; cin >> c;
      keys[i].second.emplace_back(c - 1);
    }
  }

  // i個目までのカギで集合jで表される宝箱を開けられる時の最小金額
  vector<vector<int>> dp(m + 1, vector<int>((1 << n), INT_MAX));
  dp[0][0] = 0;

  for(int i = 0; i < m; i++){
    for(int j = 0; j < (1 << n); j++){
      if(dp[i][j] != INT_MAX){
        // 鍵を買わない
        chmin(dp[i + 1][j], dp[i][j]);
        // 鍵を買う
        vector<int> current(n);
        int d = 0;
        for(int k = 0; k < n; k++) current[k] = ((1 << k) & j ? 1 : 0);
        for(int p : keys[i].second) current[p] = 1;
        for(int k = 0; k < n; k++) d += (1 << k) * current[k];
        chmin(dp[i + 1][d], dp[i][j] + keys[i].first);
      }
    }
  }
  
  cout << (dp[m][((1 << n) - 1)] != INT_MAX ? dp[m][((1 << n) - 1)] : -1) << endl;
}