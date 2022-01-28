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
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


vector<pair<int, int>> G[200000];
class LCA {
public:
    int V, logV;
    vector<int> depth, len;
    vector<vector<int> > parent;
    
    LCA(int V) {
        this->V = V;
        logV = 0;
        while (V > (1LL<<logV)) logV++;
        this->depth = vector<int>(V);
        this->len = vector<int>(V);
        this->parent = vector<vector<int> >(logV, vector<int>(V));
    }
    
    void init(int v, int par, int d, int l) {
        depth[v] = d;
        parent[0][v] = par;
        len[v] = l;
        for (int i = 0; i < (int)G[v].size(); i++) {
            int w = G[v][i].first;
            int lc = G[v][i].second;
            if (w == par) continue;
            init(w, v, d+1, lc + l);
        }
    }
    
    void build() {
        for (int k = 0; k + 1 < logV; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) parent[k+1][v] = -1;
                else parent[k+1][v] = parent[k][parent[k][v]];
            }
        }
    }
    
    int query(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (int k = 0; k < logV; k++) {
            if ((depth[v] - depth[u]) >> k & 1)
                v = parent[k][v];
        }
        if (u == v) return u;
        
        for (int k = logV-1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m, q; cin >> n >> m >> q;
  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }

  LCA lca(n);
  lca.init(0, -1, 0, 0);
  lca.build();

  while(q--){
    int x, y; cin >> x >> y;
    x--, y--;
    int w; cin >> w;
    int z = lca.query(x, y);
    cout << z << endl;
    ll rdis = lca.len[x] + lca.len[y] - 2 * lca.len[z];
    if(w < z){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}