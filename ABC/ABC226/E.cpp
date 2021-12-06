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

const ll modv = 998244353;


int main(){
  int n, m; cin >> n >> m;

  vector<vector<int>> g(n);
  dsu d(n);

  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    d.merge(u - 1, v - 1);
    g[u - 1].push_back(v - 1);
  }

  ll ans = 1;
  for(auto p : d.groups()){
    int cnt = 0, trg = p.size();
    for(auto v : p) cnt += g[v].size();
    if(cnt == trg){
      ans = (ans * 2) % modv;
    }else{
      ans = 0;
    }
  }
  
  cout << ans << endl;
}