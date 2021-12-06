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


ll op(ll a, ll b){
  return min(a, b);
}
ll e(){
  return LLONG_MAX;
}

int main(){
  int q; cin >> q;
  int n = 1 << 20;
  vector<ll> val(n, -1);

  vector<ll> v(n);
  for(int i = 0; i < n; i++) v[i] = i;

  segtree<ll, op, e> seg(v);

  query(q){
    ll t, x; cin >> t >> x;
    if(t == 1){
      ll h = x % n;
      h = seg.prod(h % n, n);
      if(h == INT_MAX){
        h = seg.all_prod();
      }
      val[h % n] = x;
      seg.set(h % n, INT_MAX);
    }else if(t == 2){
      cout << val[x % n] << endl;
    }
  }
}