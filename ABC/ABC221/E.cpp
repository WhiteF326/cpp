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
#define aryin(a, n) vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];

const ll modv = 998244353;
ll modpow(ll x, ll n){
  ll ret = 1;
  if(modv == 0){
    while(n > 0){
      if(n & 1) ret *= x;
      x *= x;
      n >>= 1;
    }
  }else{
    while(n > 0){
      if(n & 1) ret = ret * x % modv;
      x = x * x % modv;
      n >>= 1;
    }
  }
  return ret;
}
ll modinv(ll x){
  ll res = 1, k = modv - 2, y = x;
  while(k){
    if(k & 1) res = (res * y) % modv;
    y = y * y % modv;
    k /= 2;
  }
  return res;
}

ll op(ll a, ll b){
  return (a + b) % modv;
}
ll e(){
  return 0LL;
}


int main(){
  int n; cin >> n;
  aryin(a, n);

  // 座圧
  vector<int> b(a);
  sort(all(b));
  b.erase(unique(all(b)), b.end());
  vector<int> c(n);
  for(int i = 0; i < n; i++){
    c[i] = lower_bound(all(b), a[i]) - b.begin();
  }

  // 2^x list
  vector<ll> pl(n + 1, 0);
  for(int i = 1; i <= n; i++){
    pl[i] = modpow(2, i - 1);
  }
  vector<ll> mpl(n + 1, 0);
  for(int i = 1; i <= n; i++){
    mpl[i] = modv - pl[i];
  }

  segtree<ll, op, e> seg(n);
  for(int i = 1; i < n; i++){
    seg.set(c[i], (seg.get(c[i]) + pl[i]) % modv);
  }

  // inverse
  vector<ll> invl(n + 1, 0);
  for(int i = 0; i < n; i++){
    invl[i] = modinv(modpow(2, i));
  }

  ll ans = 0;
  for(int i = 0; i < n; i++){
    seg.set(c[i], (seg.get(c[i]) + mpl[i]) % modv);
    ans = (ans + (seg.prod(c[i], n) * invl[i]) % modv) % modv;
  }
  cout << ans << endl;
}