#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  vector<pair<pair<int, int>, ll>> g;

  dsu d(n);
  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    a--, b--;
    if(c < 0){
      // 負の辺は全て張る
      d.merge(a, b);
    }else{
      g.push_back(mp(mp(a, b), c));
    }
  }

  sort(all(g), [](auto const& lhs, auto const& rhs){
    return lhs.second < rhs.second;
  });

  // 正の辺を小さい順から張る
  ll ans = 0;
  for(auto ver : g){
    int l = ver.first.first;
    int r = ver.first.second;
    if(d.same(l, r)){
      ans += ver.second;
    }else{
      d.merge(l, r);
    }
  }

  cout << ans << endl;
}