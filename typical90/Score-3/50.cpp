#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n, l; cin >> n >> l;
  vector<ll> dp(n + l + 10, 0);
  dp[0] = 1LL;
  for(int i = 0; i < n; i++){
    dp[i + 1] = (dp[i] + dp[i + 1]) % 1000000007;
    dp[i + l] = (dp[i] + dp[i + l]) % 1000000007;
  }
  cout << dp[n] % 1000000007 << endl;
}