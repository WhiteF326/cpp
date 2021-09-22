#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

#define chmin(a, b) a = min(a, b)

#define infl 100000


vector<vector<int>> g(20);


int main(){
  int n, m; cin >> n >> m;
  dsu d(n);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
    d.merge(a, b);
  }

  ll ans = 1;

  auto ex = d.groups();
  for(auto el : ex){
  }

  cout << ans << endl;
}