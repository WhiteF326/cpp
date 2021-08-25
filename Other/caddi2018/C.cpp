#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
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


int main(){
  ll n; cin >> n;
  ll p; cin >> p;

  if(n > sqrt(p)){
    cout << 1 << endl;
    return 0;
  }

  ll start = ceil(pow(p, 1.0 / n));

  for(ll i = start; i >= 1LL; i--){
    ll x = modpow(i, n, 0);
    // cout << x << endl;
    if(p % x == 0){
      cout << i << endl;
      return 0;
    }
  }
}