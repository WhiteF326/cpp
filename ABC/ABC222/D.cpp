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


int main(){
  int n; cin >> n;
  vector<int> a(n), b(n);
  aryin(a, n); aryin(b, n);

  // dp[i][j] = c の i 番目が j である通り数
  vector<vector<ll>> dp(n, vector<ll>(3001, 0));

  for(int i = a[0]; i <= b[0]; i++) dp[0][i] = 1;
  for(int i = 1; i < n; i++){
    vector<ll> lsum(all(dp[i - 1]));
    for(int j = 1; j <= 3000; j++) lsum[j] = (lsum[j] + lsum[j - 1]) % modv;
    // for(int j = 0; j <= 3; j++) cout << lsum[j] << " ";
    // cout << endl;
    for(int j = a[i]; j <= b[i]; j++){
      dp[i][j] = lsum[j];
    }
  }

  ll ans = 0;
  for(int i = 0; i <= 3000; i++){
    ans = (ans + dp[n - 1][i]) % modv;
  }
  cout << ans << endl;
}