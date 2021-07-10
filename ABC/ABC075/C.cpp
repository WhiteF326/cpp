#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;
using pli = pair<ll, int>;

int main(){
  int n, m; cin >> n >> m;
  
  vector<vector<int>> g(n, vector<int>(0));
  vector<pair<int, int>> x;
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
    x.emplace_back(make_pair(a, b));
  }

  int ans = 0;
  
  for(int i = 0; i < m; i++){
    queue<int> q;
    q.push(0);
    vector<bool> visited(n, false);
    visited[0] = true;
    while(!q.empty()){
      int dest = q.front();
      q.pop();
      for(int v : g[dest]){
        if(dest == x[i].first && v == x[i].second) continue;
        if(v == x[i].first && dest == x[i].second) continue;
        if(!visited[v]){
          visited[v] = true;
          q.push(v);
        }
      }
    }
    if(accumulate(visited.begin(), visited.end(), 0) != n) ans++;
  }

  cout << ans << endl;
}