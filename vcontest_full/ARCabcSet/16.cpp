#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n = 100;
  int a, b, x, y; cin >> a >> b >> x >> y;
  vector<vector<pair<int, int>>> g(2 * n);
  for(int i = 0; i < n; i++){
    g[i].push_back({i + n, x});
    g[i + n].push_back({i, x});
  }
  for(int i = 0; i < n - 1; i++){
    g[i + 1].push_back({i + n, x});
    g[i + n].push_back({i + 1, x});
  }
  for(int i = 0; i < n - 1; i++){
    g[i].push_back({i + 1, y});
    g[i + 1].push_back({i, y});
    g[i + n].push_back({i + n + 1, y});
    g[i + n + 1].push_back({i + n, y});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({0, a - 1});
  vector<int> dist(n * 2, INT_MAX);
  while(!q.empty()){
    auto dest = q.top();
    q.pop();

    for(auto v : g[dest.second]){
      int arrive = dest.first + v.second;
      if(dist[v.first] > arrive){
        q.push({arrive, v.first});
        dist[v.first] = arrive;
      }
    }
  }

  cout << dist[b + n - 1] << endl;
}