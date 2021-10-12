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
  dsu d(n);

  vector<vector<ll>> g;

  for(int i = 0; i < n - 1; i++){
    ll u, v, w; cin >> u >> v >> w;
    u--, v--;

    vector<ll> l = {w, u, v};
    g.push_back(l);
  }

  sort(all(g), [](vector<ll> a, vector<ll> b){
    return a[0] < b[0];
  });

  ll ans = 0;
  for(vector<ll> e : g){
    ans += e[0] * d.size(e[1]) * d.size(e[2]);
    d.merge(e[1], e[2]);
  }

  cout << ans << endl;
}