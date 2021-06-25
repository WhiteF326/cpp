#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<vector<int>> g(n, vector<int>(0));

  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> dist(n, 0);
  queue<int> q; q.push(0);
  vector<bool> visited(n, false); visited[0] = true;
  while(!q.empty()){
    int dest = q.front();
    q.pop();
    for(int i = 0; i < g[dest].size(); i++){
      if(visited[g[dest][i]] == false){
        visited[g[dest][i]] = true;
        dist[g[dest][i]] = dist[dest] + 1;
        q.push(g[dest][i]);
      }
    }
  }
  int farest = max_element(dist.begin(), dist.end()) - dist.begin();

  vector<int>(n, 0).swap(dist);
  q.push(farest);
  vector<bool>(n, false).swap(visited); visited[farest] = true;
  while(!q.empty()){
    int dest = q.front();
    q.pop();
    for(int i = 0; i < g[dest].size(); i++){
      if(visited[g[dest][i]] == false){
        visited[g[dest][i]] = true;
        dist[g[dest][i]] = dist[dest] + 1;
        q.push(g[dest][i]);
      }
    }
  }
  cout << *max_element(dist.begin(), dist.end()) + 1 << endl;
}