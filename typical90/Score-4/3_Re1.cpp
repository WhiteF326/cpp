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
  vector<vector<int>> g(n);
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  auto bfs = [&](int p){
    queue<int> q;
    q.push(p);
    vector<bool> visited(n, false);
    visited[p] = true;
    vector<int> depth(n, 0);
    
    while(!q.empty()){
      int dest = q.front();
      q.pop();

      for(int v : g[dest]){
        if(visited[v]) continue;
        visited[v] = true;
        depth[v] = depth[dest] + 1;
        q.push(v);
      }
    }

    return depth;
  };

  auto first = bfs(0);
  int lft = max_element(all(first)) - first.begin();
  auto second = bfs(lft);
  cout << *max_element(all(second)) + 1 << endl;
}