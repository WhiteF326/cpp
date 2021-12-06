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

ll gcd(ll x, ll y){
  while(y > 0){
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}

int main(){
  int n, m; cin >> n >> m;
  vector<pair<ll, ll>> l(m);
  for(int i = 0; i < m; i++){
    ll a, c; cin >> a >> c;
    l[i] = mp(a, c);
  }

  sort(all(l), [](pair<ll, ll> a, pair<ll, ll> b){
    return a.second < b.second;
  });

  int cur = n;
  ll ans = 0;
  for(auto p : l){
    ans += (cur - gcd(cur, p.first)) * p.second;
    cur = gcd(cur, p.first);
  }

  if(cur == 1) cout << ans << endl;
  else cout << -1 << endl;
}