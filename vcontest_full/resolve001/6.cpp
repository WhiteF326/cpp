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
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


ll gcd(ll x, ll y){
  while(y > 0){
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll a, b, c, d; cin >> a >> b >> c >> d;
  ll ans = b - a + 1LL;
  ans -= (b / c) - (a - 1) / c;
  ans -= (b / d) - (a - 1) / d;
  ll e = gcd(c, d);
  e = c / e * d;
  ans += (b / e) - (a - 1) / e;

  cout << ans << endl;
}
