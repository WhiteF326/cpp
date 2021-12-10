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
    int l, r, a; cin >> l >> r >> a;
    g[l - 1].push_back(r - 1);
    g[r - 1].push_back(l - 1);
  }

  auto bfs = [&](int start){
    queue<int> q;
    q.push(start);
    vector<bool> visited(n, false);
    visited[start] = true;
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

  auto f = bfs(0);
  int p = max_element(all(f)) - f.begin();
  auto s = bfs(p);
  cout << *max_element(all(s)) << endl;
}