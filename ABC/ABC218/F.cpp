#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

constexpr int infl = 1000000000;

int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n);
  vector<pair<int, int>> l(m + 1);
  for(int i = 0; i < m; i++){
    int s, t; cin >> s >> t;
    s--, t--;
    g[s].emplace_back(t);
    l[i] = mp(s, t);
  }
  l[m] = {-1, -1};

  auto pairEqual = [](pair<int, int> l, pair<int, int> r){
    bool ans = false;
    if(l.first == r.first && l.second == r.second) ans = true;
    return ans;
  };

  auto dfs = [&](int start, int unabled){
    queue<int> q;
    q.push(start);
    vector<pair<int, int>> depth(n, {infl, -1});
    depth[start] = {0, -1};
    vector<bool> visited(n, false);
    visited[start] = true;

    while(!q.empty()){
      int dest = q.front();
      q.pop();

      for(int v : g[dest]){
        if(!visited[v] && !pairEqual(l[unabled], {dest, v})){
          visited[v] = true;
          depth[v] = {depth[dest].first + 1, dest};
          q.push(v);
        }
      }
    }

    return depth;
  };

  // 通常時の経路を復元
  auto stdPath = dfs(0, m);
  int pos = n - 1;
  set<pair<int, int>> paths;
  while(stdPath[pos].second != -1){
    paths.insert({stdPath[pos].second, pos});
    pos = stdPath[pos].second;
  }
  
  int stdDist = stdPath[n - 1].first;
  // 最初から移動不可能な場合
  if(stdDist == infl){
    for(int i = 0; i < m; i++) cout << -1 << endl;
    return 0;
  }

  // 削除検証
  for(int i = 0; i < m; i++){
    if(paths.find(l[i]) == paths.end()){
      cout << stdDist << endl;
    }else{
      auto inspectPath = dfs(0, i);
      if(inspectPath[n - 1].first == infl){
        cout << -1 << endl;
      }else{
        cout << inspectPath[n - 1].first << endl;
      }
    }
  }
}