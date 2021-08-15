#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
// #define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>(0, pair<int, int>()));

  for(int i = 0; i < n - 1; i++){
    int u, v, w; cin >> u >> v >> w;
    u--, v--;
    g[u].push_back(mp(w, v));
    g[v].push_back(mp(w, u));
  }
  for(int i = 0; i < n - 1; i++){
    sort(all(g[i]));
  }

  queue<int> q;
  ll ans = 0;
  q.push(0);
  vector<int> deep(n, 0);
  vector<int> depth(n, 0);
  vector<bool> visited(n, false);
  visited[0] = true;
  int cnt = 0;
  while(!q.empty()){
    auto dest = q.front();
    q.pop();
    queue<int> enq;
    for(auto gp : g[dest]){
      if(visited[gp.second]) continue;
      if(deep[gp.second] < gp.first){
        cnt++;
        visited[gp.second] = true;
        deep[gp.second] = gp.first;
        depth[gp.second] = cnt;
        ans += (ll)deep[gp.second] * (ll)depth[gp.second];
        q.push(gp.second);
      }
    }
  }
  cout << ans << endl;
}