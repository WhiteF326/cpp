#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

ll expow(ll x, ll n) {
  ll ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

int main(){
  ll n; cin >> n;
  // bは全列挙できる

  ll ans = LLONG_MAX;
  for(ll b = (ll)log2(n); b >= 0; b--){
    // aを与えるとcは線形減少する、aを最大へ
    ll a = n / expow(2, b);
    ll c = n - (a * expow(2, b));
    ans = min(ans, a + b + c);
  }
  cout << ans << endl;
}