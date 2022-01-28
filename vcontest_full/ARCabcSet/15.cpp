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
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

int n;
vector<vector<pair<int, int>>> g(100000);

vector<int> ans(100000, -1);

void dfs(int p, int c){
  ans[p] = c;
  for(auto v : g[p]){
    if(ans[v.first] != -1) continue;
    if(v.second == c){
      dfs(v.first, (v.second + 1) % n);
    }else{
      dfs(v.first, v.second);
    }
  }
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int m; cin >> n >> m;
  for(int i = 0; i < m; i++){
    int u, v, c; cin >> u >> v >> c;
    u--, v--, c--;
    g[u].push_back({v, c});
    g[v].push_back({u, c});
  }

  dfs(0, 0);

  for(int i = 0; i < n; i++) cout << ans[i] + 1 << endl;
}
