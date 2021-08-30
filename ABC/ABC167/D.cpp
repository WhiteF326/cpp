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
  ll n, k; cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }

  vector<vector<int>> dp(61, vector<int>(n + 1, 0));
  for(int i = 0; i < n; i++) dp[0][i] = a[i];
  for(int i = 1; i <= 60; i++){
    for(int j = 0; j < n; j++){
      dp[i][j] = dp[i - 1][dp[i - 1][j]];
    }
  }

  int ans = 0;
  for(int i = 60; i >= 0; i--){
    if(k & (1LL << i)) ans = dp[i][ans];
  }
  cout << ans + 1 << endl;
}