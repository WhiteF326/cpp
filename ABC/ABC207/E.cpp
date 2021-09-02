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

#define ml modint1000000007

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  // 累積和
  vector<ll> xsum(n, a[0]);
  for(int i = 1; i < n; i++) xsum[i] = xsum[i - 1] + a[i];

  // dp[l][r] = 区間l~r(rを含む)の解
  vector<vector<ml>> dp(n, vector<ml>(n, 0));
  for(int i = 0; i < n; i++){
    //
  }
}