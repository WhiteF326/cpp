#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


struct UnionFind {
  vector<int> rank, parents;
  UnionFind() {}
  UnionFind(int n) {
    rank.resize(n, 0);
    parents.resize(n, 0);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
      rank[i] = 0;
    }
  }
  bool same(int x, int y) { return find(x) == find(y); }
  bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (rank[x] > rank[y]) {
      parents[y] = x;
    } else {
      parents[x] = y;
      if (rank[x] == rank[y]) {
        rank[y]++;
      }
    }
      return true;
  }
  int find(int x) {
    if (x != parents[x]) {
      parents[x] = find(parents[x]);
    }
    return parents[x];
  }
};
struct Edge{
  int from;
  int to;
  ll weight;

  Edge(int from, int to, ll weight){
    this->from = from;
    this->to = to;
    this->weight = weight;
  }
  Edge(){
    this->from = 0;
    this->to = 0;
    this->weight = 0LL;
  }

  bool operator< (const Edge& obj){
    return this->weight < obj.weight;
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  ll mc = 0;
  vector<ll> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(a[mc] > a[i]) mc = i;
  }

  ll ans = 0;
  UnionFind uf(n);
  vector<Edge> v(m);
  for(int i = 0; i < m; i++){
    int l, r; cin >> l >> r;
    l--, r--;
    ll w; cin >> w;
    v[i] = {l, r, w};
  }

  for(int i = 0; i < n; i++){
    Edge e = Edge(mc, i, a[mc] + a[i]);
    v.push_back(e);
  }
  sort(all(v));

  for(int i = 0; i < m + n; i++){
    if(!uf.same(v[i].from, v[i].to)){
      uf.merge(v[i].from, v[i].to);
      ans += v[i].weight;
    }
  }

  cout << ans << endl;
}