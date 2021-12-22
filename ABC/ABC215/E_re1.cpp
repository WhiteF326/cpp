#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


const ll modv = 998244353;
#define mint modint998244353
int main(){
  int n; cin >> n;
  string s; cin >> s;
  vector<int> sl(n);
  for(int i = 0; i < n; i++) sl[i] = s[i] - 'A' + 1;

  // i 回目のコンテスト / j で表すコンテストに出場済み / 前回のコンテストは k
  vector<vector<vector<mint>>> dp(n + 1, vector<vector<mint>>(1024, vector<mint>(11, 0)));
  dp[0][0][0] = 1;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 1024; j++){
      for(int k = 0; k <= 10; k++){
        dp[i + 1][j][k] += dp[i][j][k];
        if(j & (1 << (sl[i] - 1)) && k != sl[i]) continue;
        dp[i + 1][j | (1 << (sl[i] - 1))][sl[i]] += dp[i][j][k];
      }
    }
  }

  mint ans = 0;
  for(int i = 1; i < 1024; i++){
    for(int j = 0; j <= 10; j++){
      ans += dp[n][i][j];
    }
  }

  cout << ans.val() << endl;
}