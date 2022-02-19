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
  
  int n, q; cin >> n >> q;
  vector<vector<int>> g(n);
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }

  // breadth first search on adjagency list g
  queue<int> que;
  que.push(0);
  vector<int> visited(n, 0);
  visited[0] = 1;
  vector<int> depth(n, INT_MAX);
  depth[0] = 0;

  while(!que.empty()){
    int dest = que.front();
    que.pop();

    for(int v : g[dest]){
      if(visited[v]) continue;
      visited[v] = 1;
      depth[v] = depth[dest] + 1;
      que.push(v);
    }
  }
}