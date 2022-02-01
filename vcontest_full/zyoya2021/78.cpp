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


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll n, m; cin >> n >> m;
  vector<vector<ll>> v(n);
  for(int i = 0; i < m; i++){
    ll a, b; cin >> a >> b;
    v[a - 1].push_back(b - 1);
  }
  
  dsu d(n);
  vector<ll> res(1, 0);
  ll ans = 0;
  for(ll i = n - 1; i >= 1; i--){
    ans++;
    for(auto j : v[i]){
      if(!d.same(i, j)){
        d.merge(i, j);
        ans--;
      }
    }
    res.push_back(ans);
  }
  reverse(all(res));
  for(ll v : res) cout << v << endl;
}