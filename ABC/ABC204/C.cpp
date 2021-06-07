#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(0));
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    queue<int> q;
    q.push(i);
    vector<bool> visited(n, false);
    visited[i] = true;
    while(!q.empty()){
      int dest = q.front();
      q.pop();
      for(int j = 0; j < g[dest].size(); j++){
        if(!visited[g[dest][j]]){
          q.push(g[dest][j]);
          ans++;
          visited[g[dest][j]] = true;
        }
      }
    }
  }
  cout << ans + n << endl;
}