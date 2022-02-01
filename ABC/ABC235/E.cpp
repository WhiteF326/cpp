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


struct Edge{
  int from;
  int to;
  ll weight;
  int no;
};
bool operator< (const Edge& a, const Edge& b){
  return a.weight < b.weight;
}
bool operator> (const Edge& a, const Edge& b){
  return a.weight > b.weight;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m, q; cin >> n >> m >> q;
  vector<Edge> e(m + q);
  for(int i = 0; i < m; i++){
    int a, b; ll c; cin >> a >> b >> c;
    a--, b--;
    e[i] = {a, b, c, -1};
  }

  vector<bool> ans(q, false);
  for(int i = 0; i < q; i++){
    int u, v; ll w; cin >> u >> v >> w;
    u--, v--;
    e[m + i] = {u, v, w, i};
  }
  sort(all(e), [](const Edge& a, const Edge& b){
    return a.weight < b.weight;
  });

  vector<ll> depth(n, 0);

  dsu d(n);
  int ptr = 0;
  for(int i = 0; i < m + q; i++){
    if(e[i].no == -1){
      if(!d.same(e[i].from, e[i].to)) d.merge(e[i].from, e[i].to);
    }else{
      if(!d.same(e[i].from, e[i].to)){
        ans[e[i].no] = true;
      }else{
        ans[e[i].no] = false;
      }
    }
  }

  for(int i = 0; i < q; i++){
    cout << (ans[i] ? "Yes" : "No") << endl;
  }
}