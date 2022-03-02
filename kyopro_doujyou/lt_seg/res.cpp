#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


struct Query{
  int l, r;
  ll c;
};
constexpr ll inf = 1000000000000000;

ll op(ll a, ll b){
  return min(a, b);
}
ll e(){
  return inf;
}
ll mapping(ll f, ll x){
  return min(x, f);
}
ll composition(ll f, ll g){
  return min(f, g);
}
ll id(){
  return inf;
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  vector<ll> d(n, inf);
  d[0] = 0;

  vector<Query> q(m);
  for(int i = 0; i < m; i++){
    cin >> q[i].l >> q[i].r >> q[i].c;
    q[i].l--;
  }
  sort(all(q), [](const Query& a, const Query& b){
    return a.l < b.l;
  });

  lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(d);

  for(Query v : q){
    ll cur = seg.prod(v.l, v.r);
    seg.apply(v.l, v.r, v.c + cur);
  }

  ll ans = seg.prod(n - 1, n);
  if(ans == inf){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
}
