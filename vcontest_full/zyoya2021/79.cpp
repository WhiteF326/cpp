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


#define infl 10000000
ll op(ll a, ll b){
  return min(a, b);
}
ll e(){
  return infl;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  vector<int> a(n);
  aryin(a, n);

  vector<ll> ms(1500001);
  for(int i = 0; i <= 1500000; i++) ms[i] = i;
  segtree<ll, op, e> seg(ms);

  for(int i = 0; i < m - 1; i++){
    seg.set(a[i], seg.get(a[i]) + infl);
  }

  ll ans = LLONG_MAX;
  for(int i = 0; i < n - m + 1; i++){
    seg.set(a[i + m - 1], seg.get(a[i + m - 1]) + infl);
    ans = min(ans, seg.all_prod());
    seg.set(a[i], seg.get(a[i]) - infl);
  }

  cout << ans << endl;
}