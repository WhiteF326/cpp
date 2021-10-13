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

ll gcd(ll x, ll y){
  while(y > 0){
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
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
  int t; cin >> t;
  query(t){
    ll n, s, k; cin >> n >> s >> k;
    ll g = gcd(n, k);
    if(g == 1 || s % g == 0){
      n /= g, s /= g, k /= g;
      ll ans = (n - s) * modinv(k, n);
      cout << ans % n << endl;
    }else{
      cout << -1 << endl;
    }
  }
}