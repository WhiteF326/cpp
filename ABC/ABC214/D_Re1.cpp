#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)


struct Edge{
  int from;
  int to;
  ll weight;

  Edge(){
    this->from = 0;
    this->to = 0;
    this->weight = 0;
  }

  Edge(int from, int to, ll weight){
    this->from = from;
    this->to = to;
    this->weight = weight;
  }
};

bool operator< (const Edge& a, const Edge& b){
  return a.weight < b.weight;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<Edge> e(n - 1);
  for(int i = 0; i < n - 1; i++){
    int u, v; cin >> u >> v;
    ll w; cin >> w;
    e[i] = Edge(u - 1, v - 1, w);
  }

  sort(all(e));

  ll ans = 0;

  dsu d(n);

  for(int i = 0; i < n - 1; i++){
    int l = e[i].from;
    int r = e[i].to;

    ll lc = d.size(l);
    ll rc = d.size(r);

    ans += lc * rc * e[i].weight;

    d.merge(l, r);
  }

  cout << ans << endl;
}