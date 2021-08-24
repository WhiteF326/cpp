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

int main(){
  int n, m; cin >> n >> m;
  vector<pair<int, int>> path(m);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    path[i] = mp(a, b);
  }
  reverse(all(path));

  ll ans = (ll)n * (ll)(n - 1) / 2LL;
  stack<ll> anslist;
  dsu d(n);

  for(int i = 0; i < m; i++){
    anslist.push(ans);
    if(d.same(path[i].first, path[i].second)) continue;
    ll left = d.size(path[i].first), right = d.size(path[i].second);
    ans = max(ans - left * right, 0LL);
    d.merge(path[i].first, path[i].second);
  }
  for(int i = 0; i < m; i++){
    cout << anslist.top() << endl;
    anslist.pop();
  }
}