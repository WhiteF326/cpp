#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// better precision power
ll mpow(ll x, ll y){
  ll ret = 1;
  while(y > 0){
    if(y & 1) ret *= x;
    x *= x;
    y >>= 1;
  }
  return ret;
}

int main(){
  ll n; cin >> n;
  if(n < 4LL){
    cout << n << endl;
  }else{
    ll ans = LLONG_MAX;
    for(ll j = 2; j <= log2(n); j++){
      ll i = pow(n, 1.0 / j);
      // fix error of i
      while(pow(i + 1, j) <= n) i++;
      ll k = n - mpow(i, j);
      ans = min(ans, i + j + k);
      cout << i << " " << j << " " << k << endl;
    }
    cout << ans << endl;
  }
}