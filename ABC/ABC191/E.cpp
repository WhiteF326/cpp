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
#define chmin(a, b) a = min(a, b)
#define pll pair<ll, ll>

int main(){
  int n, m; cin >> n >> m;
  vector<vector<pll>> g(n);
  vector<vector<pll>> h(n);

  for(int i = 0; i < m; i++){
    ll a, b, c; cin >> a >> b >> c;
    g[a - 1].push_back(mp(b - 1, c));
    h[b - 1].push_back(mp(a - 1, c));
  }

  for(int i = 0; i < n; i++){
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push(mp(0, i));
    vector<bool> visited(n, false);
    vector<ll> depth(n, INT_MAX);
    depth[i] = 0;
    while(!q.empty()){
      auto dest = q.top();
      q.pop();
 
      for(auto v : g[dest.second]){
        ll dist = dest.first + v.second;
        ll targ = v.first;
        if(!visited[targ] || depth[targ] >= dist){
          visited[targ] = true;
          depth[targ] = dist;
          q.push(mp(dist, targ));
        }
      }
 
      if(visited[i]){
        cout << depth[i] << endl;
        break;
      }
    }
    if(!visited[i]) cout << -1 << endl;
  }
}