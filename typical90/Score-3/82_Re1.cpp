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


#define lmx 1000000000000000000

ll modpow(ll x, ll n, int mod){
  ll ret = 1;
  if(mod == 0){
    while(n > 0){
      if(n & 1) ret *= x;
      x *= x;
      n >>= 1;
    }
  }else{
    while(n > 0){
      if(n & 1) ret = ret * x % mod;
      x = x * x % mod;
      n >>= 1;
    }
  }
  return ret;
}
const ll modv = 1000000007;
int main(){
  ll l, r; cin >> l >> r;
  if(l == r && l == lmx){
    cout << 19 << endl;
    return 0;
  }

  ll ans = r == lmx;
  for(int i = 0; i < 18; i++){
    ll ls = max(modpow(10, i, 0), l);
    ll rs = min(modpow(10, i + 1, 0) - 1LL, r);
    if(rs - ls + 1 < 0) continue;

  }

  cout << ans << endl;
}