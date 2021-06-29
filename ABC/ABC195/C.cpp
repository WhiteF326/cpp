#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
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
  ll ans = 0;
  int maxc = log10(n) / 3;
  for(int i = 1; i <= maxc; i++){
    ans += ((min(modpow(10, (i + 1) * 3, 0) - 1, n) - (modpow(10, i * 3, 0) - 1))) * (ll)i;
  }
  cout << ans << endl;
}