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

int main(){
  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> g(n, vector<int>(0));
  dsu ds(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
    ds.merge(a, b);
  }
  for(int i = 0; i < n; i++) sort(all(g[i]));
  vector<vector<int>> block(n, vector<int>(0));
  for(int i = 0; i < k; i++){
    int c, d; cin >> c >> d;
    c--, d--;
    block[c].emplace_back(d);
    block[d].emplace_back(c);
  }
  vector<int> anslist(n, 0);

  for(int i = 0; i < n; i++){
    int res = ds.size(i) - 1;
    res -= g[i].size();
    for(auto blocks : block[i]){
      if(ds.same(blocks, i) && !binary_search(all(g[i]), blocks)) res--;
    }
    anslist[i] = res;
  }
  for(int i = 0; i < n; i++) cout << anslist[i] << " ";
  cout << endl;
}