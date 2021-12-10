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


int main(){
  int n; cin >> n;
  vector<pair<int, int>> p(n);
  for(int i = 0; i < n; i++){
    cin >> p[i].first >> p[i].second;
  }
  ll m = n;

  dsu d(n);
  vector<pair<int, ll>> edges(0);

  vector<int> pl(n);
  for(int i = 0; i < n; i++) pl[i] = i;

  // x 座標
  sort(all(pl), [&](int a, int b){
    return p[a].first < p[b].first;
  });
  for(int i = 0; i < n - 1; i++){
    ll l = pl[i], r = pl[i + 1];
    int dist = min(abs(p[l].first - p[r].first), abs(p[l].second - p[r].second));
    edges.push_back({dist, l * m + r});
  }
  // y 座標
  sort(all(pl), [&](int a, int b){
    return p[a].second < p[b].second;
  });
  for(int i = 0; i < n - 1; i++){
    ll l = pl[i], r = pl[i + 1];
    int dist = min(abs(p[l].first - p[r].first), abs(p[l].second - p[r].second));
    edges.push_back({dist, l * m + r});
  }

  // クラスカル法
  ll ans = 0;
  sort(all(edges));
  for(auto p : edges){
    ll l = p.second / m, r = p.second % m;
    if(d.same(l, r)) continue;
    d.merge(l, r);
    ans += (ll)p.first;
  }

  cout << ans << endl;
}