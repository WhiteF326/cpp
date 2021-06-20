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

int main(){
  ll w, h, x, y; cin >> w >> h >> x >> y;

  // phase 1
  ld ans1 = w * h / 2.0;
  cout << fs(12) << ans1 << " ";

  // phase 2
  bool ans2 = false;
  if(x * 2 == w && y * 2 == h) ans2 = true;
  cout << ans2 << endl;
}