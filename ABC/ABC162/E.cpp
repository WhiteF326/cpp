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


const ll modv = 1000000007;

ll modpow(ll x, ll n, int mod){
  if(x == 0 && n == 0) return 1;
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
  ll ans = 0;

  vector<ll> facts(n + 10, 1);
  for(int i = 1; i <= n; i++) facts[i] = (facts[i - 1] * i) % modv;
  vector<ll> invs(n + 10, 1);
  for(int i = 0; i <= n; i++) invs[i] = modpow(facts[i], modv - 2, modv);
  vector<ll> combs(n + 10, 1);
  for(int i = 1; i <= n; i++){
    ll res = (facts[i] * facts[n - i]) % modv;
    combs[i] = (facts[n] * modpow(res, modv - 2, modv)) % modv;
  }

  map<int, ll> cntr;
  for(int i = 1; i <= k; i++) cntr[k / i] = (cntr[k / i] + i) % modv;

  for(auto p : cntr){
    ll res = 0;
    for(int i = 1; i <= n; i++){
      res = (res + combs[i] * modpow(p.first - 1, n - i, modv)) % modv;
    }
    ans = (ans + res * p.second) % modv;
  }

  cout << ans << endl;
}