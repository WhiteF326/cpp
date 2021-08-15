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

const ll modv = 1000000007;

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  if(n == 1){
    cout << a[0] << endl;
    return 0;
  }

  vector<vector<ll>> dp(n, vector<ll>(2, 0));
  dp[0][0] = a[0];
  dp[0][1] = -a[1];

  for(int i = 1; i < n; i++){
    dp[i][0] += dp[i - 1][0] + a[i];
    dp[i][0] += dp[i - 1][1] + a[i];
    dp[i][0] %= modv;

    dp[i][1] += dp[i - 1][0] - a[i];
    dp[i][1] %= modv;
  }
  cout << (dp[n - 1][0] + dp[n - 1][1]) % modv << endl;
}