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
#define chmin(a, b) a = min(a, b)


ll modv = 998244353;
int n;
vector<vector<int>> g(200000);
int dim;
ll ans = 0;
vector<bool> vis(200000, 0);

struct S{
  int value;
  int size;
};
S op(S a, S b){
  return {(a.value == dim) + (b.value == dim), a.size + b.size};
};
S e(){
  return {0, 0};
}
S mapping(int f, S x){
  return {x.value + f * x.size, x.size};
}
int composition(int f, int g){
  return f + g;
}
int id(){
  return 0;
}

lazy_segtree<S, op, e, int, mapping, composition, id> seg(200000);

void dfs(int p){
  if(vis[p]) return;
  vis[p] = true;

  
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    int u, v; cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }

  auto dfs = [&](int p){
    queue<int> q;
    q.push(p);
    vector<bool> visited(n, 0);
    visited[p] = 1;
    vector<int> depth(n, INT_MAX);
    depth[p] = 0;

    while(!q.empty()){
      int dest = q.front();
      q.pop();

      for(int v : g[dest]){
        if(!visited[v]){
          visited[v] = true;
          depth[v] = depth[dest] + 1;
          q.push(v);
        }
      }
    }

    return depth;
  };

  auto vd = dfs(0);
  int sp = max_element(all(vd)) - vd.begin();
  auto pl = dfs(sp);

  dim = *max_element(all(pl));

  for(int i = 0; i < n; i++){
    seg.set(i, {pl[i], 1});
  }

  dfs(0);

  cout << ans << endl;
}