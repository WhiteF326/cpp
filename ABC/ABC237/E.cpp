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
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  vector<ll> h(n);
  aryin(h, n);

  vector<vector<pair<int, int>>> g(n);

  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    u--, v--;
    if(h[v] > h[u]){
      g[v].push_back({u, -(h[v] - h[u])});
      g[u].push_back({v, -2LL * (h[u] - h[v])});
    }else if(h[v] < h[u]){
      g[v].push_back({u, -2LL * (h[v] - h[u])});
      g[u].push_back({v, -(h[u] - h[v])});
    }else{
      g[v].push_back({u, 0});
      g[u].push_back({v, 0});
    }
  }

  vector<ll> dist(n, LLONG_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({0, 0});
  dist[0] = 0;

  while(!q.empty()){
    auto dest = q.top();
    q.pop();

    for(auto v : g[dest.second]){
      ll arrive = dist[dest.second] + v.second;
      if(dist[v.first] > arrive){
        dist[v.first] = arrive;
        q.push({arrive, v.first});
      }
    }
  }
  
  ll ans = -*min_element(all(dist));
  cout << ans << endl;
}
