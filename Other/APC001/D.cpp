#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


class Edge{
  public:
    int l, r;
    ll cost;

  Edge(int l, int r, ll cost){
    this->l = l;
    this->r = r;
    this->cost = cost;
  }
};


int main(){
  int n, m; cin >> n >> m;
  vector<int> a(n); aryin(a, n);

  if(m == n - 1){
    cout << 0 << endl;
    return 0;
  }else if(n < 2 * (n - m - 1)){
    cout << "Impossible" << endl;
    return 0;
  }

  dsu d(n);
  vector<vector<int>> g(n);
  for(int i = 0; i < m; i++){
    int x, y; cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    d.merge(x, y);
  }
  
  auto vx = d.groups();
  vector<priority_queue<pdesc(int)>> gv(vx.size());
  for(int l = 0; l < vx.size(); l++){
    for(int v : vx[l]) gv[l].push(a[v]);
  }

  ll ans = 0;
  for(auto &x : gv){
    ans += x.top();
    x.pop();
  }

  ll lim = 2 * (n - m - 1) - gv.size();

  priority_queue<pdesc(int)> pq;
  for(auto &x : gv){
    while(!x.empty()){
      pq.push(x.top());
      x.pop();
    }
  }
  for(int i = 0; i < lim; i++){
    if(pq.empty()){
      cout << "Impossible" << endl;
      return 0;
    }else{
      ans += pq.top();
      pq.pop();
    }
  }

  cout << ans << endl;
}