#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


ll op(ll a, ll b){
  return min(a, b);
}
ll e(){
  return LLONG_MAX;
}
ll mapping(ll f, ll x){
  return x + f;
}
ll composition(ll f, ll g){
  return f + g;
}
ll id(){
  return 0;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  ll x; cin >> x;

  vector<ll> a(n);
  aryin(a, n);

  for(int i = 0; i < n; i++){
    a[n - 1 - i] += x * i;
  }

  lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(a);

  ll ans = 0;
  for(int i = n - 1; i >= 0; i--){
    for(int j = 0; j < n; j++){
      cout << seg.get(j) << " ";
    }cout << endl;
    ans += seg.all_prod();
    seg.apply(0, n, -x);
    seg.set(i, seg.get(i) + n * x);
  }

  cout << ans << endl;
}