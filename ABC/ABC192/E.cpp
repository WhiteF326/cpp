#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;
using pli = pair<ll, int>;

ll ceilby(ll x, ll y){
  return y * ((x + y - 1LL) / y);
}

int main(){
  int n, m; cin >> n >> m;
  int x, y; cin >> x >> y;
  x--, y--;

  vector<vector<tuple<int, ll, ll>>> g(n, vector<tuple<int, ll, ll>>(0));
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    ll t, k; cin >> t >> k;
    a--, b--;
    g[a].push_back(make_tuple(b, t, k));
    g[b].push_back(make_tuple(a, t, k));
  }

  priority_queue<pair<ll, int>> q;
  q.push(make_pair(0, x));
  vector<ll> dist(n, LLONG_MAX);
  dist[x] = 0;
  vector<bool> visited(n, false);
  while(!q.empty()){
    auto dest = q.top();
    q.pop();
    if(visited[dest.second] || dist[dest.second] < dest.first) continue;
    visited[dest.second] = true;
    for(auto v : g[dest.second]){
      if(dist[get<0>(v)] > ceilby(dest.first, get<2>(v)) + get<1>(v)){
        dist[get<0>(v)] = ceilby(dest.first, get<2>(v)) + get<1>(v);
        q.push({dist[get<0>(v)], get<0>(v)});
      }
    }
  }
  if(dist[y] == LLONG_MAX){
    cout << -1 << endl;
  }else cout << dist[y] << endl;
}