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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


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
  int n, m; cin >> n >> m;
  vector<ll> dp(n, inf - 1);
  dp[0] = 0;
  lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(dp);

  vector<pair<int, int>> ord(m);
  vector<int> l(m), r(m), c(m);
  
  for(int i = 0; i < m; i++){
    int lv, rv, cv; cin >> lv >> rv >> cv;
    lv--;
    ord[i] = mp(lv, i);
    l[i] = lv, r[i] = rv, c[i] = cv;
  }

  sort(all(ord), [](pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
  });

  for(int i = 0; i < m; i++){
    int q = ord[i].second;
    ll cur = seg.prod(l[q], l[q] + 1);
    seg.apply(l[q], r[q], cur + c[q]);
  }

  ll ans = seg.prod(n - 1, n);

  cout << (ans == inf - 1 ? -1 : ans) << endl;
}