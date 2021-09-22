#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

ll modv = 998244353;

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


int main(){
  ll n; cin >> n;
  ll a, b; cin >> a >> b;
  ll k; cin >> k;

  // nCr = n! \ (r! * (n-r)!)

  vector<ll> fact(300001, 1);
  for(int i = 2; i <= 300000; i++) fact[i] = (fact[i - 1] * i) % modv;

  ll ans = 0;

  for(int i = 0; i <= n; i++){
    ll ac = a * i;
    if((k - ac) % b) continue;

    ll bc = (k - ac) / b;
    if(bc > n || bc < 0) continue;

    ll t = 1;
    // nCa
    t = ((t * fact[n] % modv) * modinv(fact[i] * fact[n - i])) % modv;
    // nCb
    t = ((t * fact[n] % modv) * modinv(fact[bc] * fact[n - bc])) % modv;

    ans = (ans + t) % modv;
  }

  cout << ans << endl;
}
