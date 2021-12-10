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


int n;
vector<vector<int>> g(100000);
vector<bool> visited(100000, 0);
vector<int> access(0);
vector<int> depth(100000, 0);

void dfs(int p){
  visited[p] = true;
  access.push_back(p);
  for(int v : g[p]){
    if(visited[v]) continue;
    depth[v] = depth[p] + 1;
    dfs(v);
    access.push_back(p);
  }
}

struct sp{
  int depth;
  int v;
};
sp op(sp a, sp b){
  if(a.depth < b.depth) return a;
  else return b;
}
sp e(){
  return {INT_MAX, -1};
}

int main(){
  cin >> n;
  for(int i = 0; i < n - 1; i++){
    int x, y; cin >> x >> y;
    g[x - 1].push_back(y - 1);
    g[y - 1].push_back(x - 1);
  }

  dfs(0);

  int m = access.size();

  vector<sp> s(m);
  vector<int> f(n, -1);
  for(int i = 0; i < m; i++){
    s[i] = {depth[access[i]], access[i]};
    if(f[access[i]] != -1) continue;
    f[access[i]] = i;
  }

  segtree<sp, op, e> seg(s);

  int q; cin >> q;

  queue<int> anslist;

  query(q){
    int a, b; cin >> a >> b;
    int l = f[a - 1], r = f[b - 1];
    int lv = min(l, r), rv = max(l, r);
    int lca = seg.prod(lv, rv + 1).depth;
    anslist.push(depth[a - 1] + depth[b - 1] - 2 * lca + 1);
  }

  while(!anslist.empty()){
    cout << anslist.front() << endl;
    anslist.pop();
  }
}