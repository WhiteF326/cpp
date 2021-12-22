#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  int n; cin >> n;
  int m; cin >> m;

  vector<pair<int, int>> p(m + 1);
  map<int, vector<pair<int, int>>> ms;
  map<int, int> xl;
  map<pair<int, int>, int> gp;
  
  p[0] = {0, n};
  for(int i = 0; i < m; i++){
    int x, y; cin >> x >> y;
    p[i + 1] = {x, y};
    xl[y] = max(xl[y], x);
    ms[y].push_back({x, i + 1});
  }

  for(auto& x : ms) sort(all(x.second));

  int lc = 0;

  vector<vector<int>> g(m + 2);
  for(int i = 0; i < m + 1; i++){
    int x = p[i].first, y = p[i].second;
    pair<int, int> a = {x, i + 1};
    
    auto ls = ms[y - 1];
    auto litr = upper_bound(all(ls), a);
    if(litr != ls.end()){
      auto tox = *litr;
      g[i].push_back(tox.second);
      lc++;
    }
    auto rs = ms[y + 1];
    auto ritr = upper_bound(all(rs), a);
    if(ritr != rs.end()){
      auto tox = *ritr;
      g[i].push_back(tox.second);
      lc++;
    }
  }

  // for(int i = 0; i < m + 1; i++){
  //   for(int v : g[i]) cout << v << " ";
  //   cout << endl;
  // }

  queue<int> q;
  q.push(0);
  vector<int> visited(m + 2, false);
  visited[0] = true;
  set<int> anslist;

  while(!q.empty()){
    int dest = q.front();
    q.pop();

    auto pr = p[dest];

    if(xl[pr.second] == pr.first){
      anslist.insert(pr.second);
    }

    for(int v : g[dest]){
      if(visited[v]) continue;
      visited[v] = true;
      q.push(v);
    }
  }

  cout << anslist.size() << endl;
}