#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

constexpr int modv = 1000000007;

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
  ll n, k; cin >> n >> k;
  if(n == 1LL) cout << k % modv << endl;
  else if(n == 2LL) cout << k * (k - 1) % modv << endl;
  else cout << k * (k - 1) % modv * modpow(k - 2, n - 2, modv) % modv << endl;
}