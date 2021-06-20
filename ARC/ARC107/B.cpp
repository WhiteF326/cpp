#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

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

ll ct(ll target, ll mx){
  if(target - 1 < mx * 2 + 1 - target) return target - 1;
  else return mx * 2 + 1 - target;
}

int main(){
  ll n, k; cin >> n >> k;
  k = abs(k);
  // e - f = kとなるe
  ll ans = 0;
  for(ll e = k + 2; e <= n * 2; e++){
    // a + b = eであるa, bの組み合わせ * 同様にf
    ans += ct(e, n) * ct(e - k, n);
  }
  cout << ans << endl;
}