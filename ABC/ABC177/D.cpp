#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  vector<set<int>> g(n, set<int>());
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].insert(b);
    g[b].insert(a);
  }
  int ans = 0;
  
  vector<bool> visited(n, false);
  for(int i = 0; i < n; i++){
    if(visited[i]) continue;

    int res = 1;
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while(!q.empty()){
      int dest = q.front();
      q.pop();
      for(auto itr = g[dest].begin(); itr != g[dest].end(); itr++){
        if(visited[*itr] == false){
          q.push(*itr);
          visited[*itr] = true;
          res++;
        }
      }
    }

    ans = max(ans, res);
  }
  cout << ans << endl;
}               