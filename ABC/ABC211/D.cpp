#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

constexpr int infl = 1000000000;
constexpr ll modv = 1000000007;

int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }

  queue<int> q;
  q.push(0);
  vector<int> depth(n, infl);
  depth[0] = 0;
  vector<int> pathcnt(n, 0);
  pathcnt[0] = 1;

  while(!q.empty()){
    int dest = q.front();
    q.pop();
    for(int v : g[dest]){
      if(depth[v] == infl){
        depth[v] = depth[dest] + 1;
        pathcnt[v] = pathcnt[dest];
        q.push(v);
      }else if(depth[v] == depth[dest] + 1){
        pathcnt[v] = (pathcnt[v] + pathcnt[dest]) % modv;
      }
    }
  }

  cout << pathcnt[n - 1] << endl;
}