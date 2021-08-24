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

#define ml modint998244353

int main(){
  int n; cin >> n;
  string s; cin >> s;
  vector<int> parse(n);
  for(int i = 0; i < n; i++) parse[i] = s[i] - 'A' + 1;

  // dp[i][j] = i個目のコンテスト、出場済みコンテスト:j、直前:k
  vector<vector<vector<ml>>> dp(n + 1, vector<vector<ml>>(1024, vector<ml>(11, 0)));
  dp[0][0][0] = 1;

  for(int i = 0; i < n; i++){
    int next = parse[i];
    for(int j = 0; j < 1024; j++){
      for(int k = 0; k <= 10; k++){
        // 出場しない
        dp[i + 1][j][k] += dp[i][j][k];
        
        // 出場する
        if(k != next && (j & (1 << (next - 1)))) continue;
        int alr = j | (1 << (next - 1));
        dp[i + 1][alr][next] += dp[i][j][k];
      }
    }
  }

  ml ans = 0;
  for(int i = 1; i < 1024; i++){
    for(int j = 0; j <= 10; j++){
      ans += dp[n][i][j];
    }
  }
  cout << ans.val() << endl;
}