#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  int q; cin >> q;
  vector<vector<int>> g(n, vector<int>(0));
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }

  queue<int> qu;
  qu.push(0);
  vector<bool> visited(n, false);
  visited[0] = true;
  vector<int> dist(n, INT_MAX);
  dist[0] = 0;
  while(!qu.empty()){
    int dest = qu.front();
    qu.pop();
    for(int i = 0; i < g[dest].size(); i++){
      if(!visited[g[dest][i]]){
        visited[g[dest][i]] = true;
        dist[g[dest][i]] = dist[dest] + 1;
        qu.push(g[dest][i]);
      }
    }
  }

  for(int i = 0; i < q; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    if((dist[a] + dist[b]) % 2) cout << "Road" << endl;
    else cout << "Town" << endl;
  }
}