#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

#define infl 1500001

ll op(ll a, ll b){
  return min(a, b);
}
ll e(){
  return infl;
}

int main(){
  int n, m; cin >> n >> m;

  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  vector<ll> mexset(1500001);
  for(int i = 0; i <= 1500000; i++) mexset[i] = (ll)i;
  segtree<ll, op, e> seg(mexset);

  for(int i = 0; i < m - 1; i++){
    seg.set(a[i], seg.get(a[i]) + infl);
  }

  ll ans = INT_MAX;
  for(int i = 0; i < n - m + 1; i++){
    seg.set(a[i + m - 1], seg.get(a[i + m - 1]) + infl);
    ans = min(ans, seg.all_prod());
    seg.set(a[i], seg.get(a[i]) - infl);
  }

  cout << ans << endl;
}