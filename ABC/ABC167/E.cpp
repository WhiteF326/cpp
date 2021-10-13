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

ll modinv(ll x){
  x %= modv;
    ll res = 1, k = modv - 2, y = x;
    while(k){
      if(k & 1) res = (res * y) % modv;
      y = y * y % modv;
      k /= 2;
    }
    return res;
  }

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
  ll n, m, k; cin >> n >> m >> k;

  if(m == 1){
    if(n - k == 1){
      cout << 1 << endl;
    }else{
      cout << 0 << endl;
    }
    return 0;
  }

  vector<ll> factlist(n + 1, 1);
  for(ll i = 2; i <= n; i++) factlist[i] = (factlist[i - 1] * i) % modv;

  ll ans = (m * modpow(m - 1, n - 1, modv)) % modv;
  ll res = ans;
  for(int i = 1; i <= k; i++){
    res = (res * modinv(m - 1)) % modv;
    ll t = res;
    ll c = (factlist[n - 1] * modinv(factlist[i] * factlist[n - 1 - i])) % modv;
    ans = (ans + (t * c) % modv) % modv;
  }
  cout << ans << endl;
}