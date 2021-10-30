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
  int n, u, v; cin >> n >> u >> v;
  u--, v--;

  vector<vector<int>> g(n);
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  
  // v からの距離を計算
  queue<int> q;
  q.push(v);
  vector<int> depth(n, INT_MAX), visited(n, 0);
  depth[v] = 0, visited[v] = 1;
  while(!q.empty()){
    int dest = q.front();
    q.pop();

    for(int x : g[dest]){
      if(!visited[x]){
        visited[x] = 1;
        depth[x] = depth[dest] + 1;
        q.push(x);
      }
    }
  }

  // u から bfs
  q.push(u);
  vector<int> ad(n, INT_MAX);
  ad[u] = 0;
  fill(all(visited), 0);
  visited[u] = 0;
  while(!q.empty()){
    int dest = q.front();
    q.pop();

    bool stp = true, p = false;
    int dist = ad[dest] + 1;

    for(int x : g[dest]){
      if(dist < depth[x] && !visited[x]){
        ad[x] = dist;
        q.push(x);
        stp = false;
        visited[x] = 1;
      }else{
        p = p | (dist == depth[x]);
      }
    }

    if(stp && q.empty()){
      cout << ad[dest] + p << endl;
      break;
    }
  }
}