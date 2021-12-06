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

#define pil pair<int, ll>
#define pli pair<ll, int>


int main(){
  int n, m; cin >> n >> m;
  vector<vector<pil>> g(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    ll c; cin >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  auto djk = [&](int start){
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, start});

    vector<ll> depth(n, LLONG_MAX);
    depth[start] = 0;

    while(!pq.empty()){
      auto dest = pq.top();
      pq.pop();

      for(auto v : g[dest.second]){
        ll arrive = v.second + dest.first;
        if(depth[v.first] > arrive){
          depth[v.first] = arrive;
          pq.push({arrive, v.first});
        }
      }
    }

    return depth;
  };

  auto fl = djk(0);
  auto el = djk(n - 1);

  for(int i = 0; i < n; i++){
    cout << fl[i] + el[i] << endl;
  }
}