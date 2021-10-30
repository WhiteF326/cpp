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
#define pll pair<ll, ll>


int main(){
  int n, m; cin >> n >> m;
  vector<vector<pll>> g(n);
  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    a--, b--;
    g[a].push_back(mp(b, c));
  }

  for(int i = 0; i < n; i++){
    // distance, vertex
    pll start = {0, i};
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(start);
    vector<ll> depth(n, LLONG_MAX);
    depth[i] = LLONG_MAX;

    while(!pq.empty()){
      pll dest = pq.top();
      pq.pop();

      for(pll v : g[dest.second]){
        ll dist = 0;
        if(dest.second == i){
          dist = v.second;
        }else{
          dist = v.second + depth[dest.second];
        }
        // cout << dest.second << " " << v.first << " " << dist << endl;
        if(depth[v.first] > dist){
          depth[v.first] = dist;
          pq.push({dist, v.first});
        }
      }
    }
    
    if(depth[i] != LLONG_MAX){
      cout << depth[i] << endl;
    }else{
      cout << -1 << endl;
    }
  }
}