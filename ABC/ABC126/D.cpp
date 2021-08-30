#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;

  vector<vector<pair<int, int>>> g(n);
  for(int i = 0; i < n - 1; i++){
    int u, v, w; cin >> u >> v >> w;
    u--, v--, w %= 2;
    g[u].push_back(mp(v, w));
    g[v].push_back(mp(u, w));
  }

  vector<int> depth(n, INT_MAX);
  depth[0] = 0;
  vector<bool> visited(n, false);
  visited[0] = 0;
  deque<int> q;
  q.push_back(0);

  while(!q.empty()){
    int dest = q.front();
    q.pop_front();

    for(auto v : g[dest]){
      if(!visited[v.first]){
        visited[v.first] = true;
        depth[v.first] = (depth[dest] + v.second) % 2;
        if(v.second) q.push_back(v.first);
        else q.push_front(v.first);
      }
    }
  }

  for(int i = 0; i < n; i++) cout << depth[i] << endl;
}