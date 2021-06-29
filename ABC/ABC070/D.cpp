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
  vector<vector<pair<int, ll>>> g(n);
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    ll c; cin >> c;
    g[a].emplace_back(make_pair(b, c));
    g[b].emplace_back(make_pair(a, c));
  }

  int q, k; cin >> q >> k; k--;
  // 最初にkからダイクストラ法
  vector<ll> distK(n, LLONG_MAX);
  distK[k] = 0;
  priority_queue<pair<ll, int>> que;
  que.push(make_pair(0, k));
  while(!que.empty()){
    auto dest = que.top();
    que.pop();
    for(int i = 0; i < g[dest.second].size(); i++){
      if(distK[g[dest.second][i].first] > dest.first + g[dest.second][i].second){
        distK[g[dest.second][i].first] = dest.first + g[dest.second][i].second;
        que.push(make_pair(dest.first + g[dest.second][i].second, g[dest.second][i].first));
      }
    }
  }

  // for(int i = 0; i < n; i++){
  //   cout << distK[i] << " ";
  // }cout << endl;

  for(int i = 0; i < q; i++){
    int x, y; cin >> x >> y; x--, y--;
    cout << distK[x] + distK[y] << endl;
  }
}