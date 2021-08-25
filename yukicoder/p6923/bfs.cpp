#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, k; cin >> n >> m >> k;
  int a, b; cin >> a >> b;
  a--, b--;
  vector<vector<int>> g(n, vector<int>(0));
  for(int i = 0; i < m; i++){
    int x, y; cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  queue<int> q;
  q.push(a);
  vector<int> depth(n, INT_MAX);
  depth[a] = 0;
  vector<bool> visited(n, false);
  visited[a] = true;

  while(!q.empty()){
    int dest = q.front();
    q.pop();
    for(int v : g[dest]){
      if(!visited[v]){
        visited[v] = true;
        depth[v] = depth[dest] + 1;
        q.push(v);
      }
    }
  }
  if(k == depth[b]){
    cout << "shortest" << endl;
  }else{
    cout << k - depth[b] << endl;
  }
}