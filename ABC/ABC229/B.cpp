#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
#define all(x) x.begin(), x.end()
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
  ll a, b; cin >> a >> b;
  for(int i = 0; i <= 18; i++){
    if(((ll)(a / modpow(10, i, 0)) % 10) + ((ll)(b / modpow(10, i, 0)) % 10) >= 10){
      cout << "Hard" << endl;
      return 0;
    }
  }
  cout << "Easy" << endl;
}