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

ll modv = 998244353;
#define madd(a, b) a = (a + b) % modv


int main(){
  int n; cin >> n;
  vector<ll> a(n); aryin(a, n);

  // dp[i][j] = i 手目で左端を j にする方法の数

  vector<vector<ll>> dp(n, vector<ll>(10, 0));
  dp[0][a[0]] = 1;
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j <= 9; j++){
      if(!dp[i][j]) continue;
      // op F
      madd(dp[i + 1][(j + a[i + 1]) % 10], dp[i][j]);
      // op G
      madd(dp[i + 1][(j * a[i + 1]) % 10], dp[i][j]);
    }
  }

  for(int i = 0; i <= 9; i++){
    cout << dp[n - 1][i] << endl;
  }
}