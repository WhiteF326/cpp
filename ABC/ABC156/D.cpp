#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

ll modv = 1000000007;

ll modpow(ll x, ll n){
  ll ans = 1;
  while(n > 0){
    if(n & 1) ans = ans * x % modv;
    x = x * x % modv;
    n >>= 1;
  }
  return ans;
}

ll modinv(ll a, ll m) {
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

int main(){
  int n, a, b; cin >> n >> a >> b;
  vector<ll> fact_table(200001, 0);
  fact_table[0] = 1;
  for(int i = 1; i <= 200000; i++) fact_table[i] = fact_table[i - 1] * i % modv;

  // 総和
  ll ans = (modpow(2, n) + modv - 1) % modv;
  // nCaとnCbを求める
  ll nca = 1, ncb = 1;
  for(int i = 0; i < a; i++){
    nca = nca * (n - i) % modv;
  }nca *= modinv(fact_table[a], modv);
  nca %= modv;
  for(int i = 0; i < b; i++){
    ncb = ncb * (n - i) % modv;
  }ncb *= modinv(fact_table[b], modv);
  ncb %= modv;
  
  ans = (ans - nca - ncb + 2 * modv) % modv;
  cout << ans << endl;
}