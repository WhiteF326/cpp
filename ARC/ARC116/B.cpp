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


const ll modv = 998244353;

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
ll modinv(ll x, ll modv){
  ll b = modv, u = 1, v = 0;
  while(b){
    ll t = x / b;
    x -= t * b;
    swap(x, b);
    u -= t *v;
    swap(u, v);
  }
  u %= modv;
  if(u < 0) u += modv;
  return u;
}

int main(){
  int n; cin >> n;
  vector<ll> a(n); aryin(a, n);

  sort(all(a));
  vector<ll> b(all(a));

  ll ans = 0;
  for(int i = 0; i < n; i++){
    ans = (ans + modpow(a[i], 2, modv)) % modv;
  }

  for(int i = 0; i < n - 1; i++){
    a[i + 1] = (a[i + 1] * modpow(2, i, modv)) % modv;
  }
  for(int i = 0; i < n - 1; i++) a[i + 1] = (a[i] + a[i + 1]) % modv;

  for(int i = 0; i < n; i++){
    ll cur = modpow(2, i, modv);
    ans = (ans + b[i] * ((((a[n - 1] - a[i] + modv) % modv) * modinv(cur, modv)) % modv)) % modv;
  }

  cout << ans << endl;
}