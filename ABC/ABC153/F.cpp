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

ll op(ll a, ll b){return a ^ b;}
ll e(){return 0;}

int main(){
  int n, d, a; cin >> n >> d >> a;
  vector<ll> pt(n), h(n);
  for(int i = 0; i < n; i++) cin >> pt[i] >> h[i];

  segtree<ll, op, e> seg(h);

  ll ans = 0;

  for(int i = 0; i < n; i++){
    if(!seg.get(i)) continue;
    ll pos = pt[i];
    ll end = upper_bound(all(pt), pos + 2 * d) - pt.begin();

    ll c = ceil(seg.get(i) / (ld)a);
    ans += c;

    for(int j = i; j <= end; j++){
      seg.set(j, max(seg.get(i) - c * a, 0LL));
    }
  }

  cout << ans << endl;
}