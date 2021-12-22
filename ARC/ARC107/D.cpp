#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


#define mint modint998244353
ostream& operator<< (ostream& os, const mint& v){
  os << v.val();
  return os;
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, k; cin >> n >> k;

  if(n == k){
    cout << 1 << endl;
    return 0;
  }

  // dp[i][j] = i 個の状態から遷移して、j 個で総和 k を達成
  vector<vector<mint>> dp(n + 1, vector<mint>(n + 1, 0));

  dp[0][k] = 1;
  dp[k][k + 1] = 1;
  if(2 * k + 1 <= n){
    dp[k][2 * k + 1] = -1;
  }

  for(int i = 1; i < n; i++){
    for(int j = 1; j <= n; j++){
      dp[i][j] += dp[i][j - 1];
    }
    for(int j = 0; j < n; j++){
      // 2 倍まで
      dp[j][j + 1] += dp[i][j];
      int access = 3 * j - 2 * i + 1;
      if(0 <= access && access <= n) dp[j][access] -= dp[i][j];
    }
  }

  mint ans = 0;
  for(int i = 0; i <= n; i++){
    // cout << dp[i][n] << endl;
    ans += dp[i][n];
  }
  cout << ans << endl;
}