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

ll modpow(ll x, ll n, ll mod){
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
  ifstream ifs("random_31.txt");
  int n; ifs >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) ifs >> a[i];

  ll ans = 0;
  for(int i = 0; i <= 63; i++){
    ll p = 0, q = 0;
    for(int j = 0; j < n; j++){
      if(a[j] & (1LL << i)) p++;
      else q++;
    }
    ans += ((p * q) % modv) * modpow(2LL, (ll)i, modv);
    ans = ans % modv;
  }
  cout << ans << endl;
}