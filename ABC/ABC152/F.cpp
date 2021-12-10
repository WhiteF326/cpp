#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


ll modpow(ll x, ll n, int mod){
  ll ret = 1;
  if(mod == 0){
    while(n > 0){
      if(n & 1) ret *= x;
      x *= x;
      n >>= 1;
    }
  }else{
    while(n > 0){
      if(n & 1) ret = ret * x % mod;
      x = x * x % mod;
      n >>= 1;
    }
  }
  return ret;
}

vector<vector<bool>> s(50, vector<bool>(50, false));
vector<vector<pair<int, int>>> g(50);
vector<bool> visited(50, false);
vector<int> depth(50, INT_MAX);

void dfs(int p){
  if(visited[p]) return;
  visited[p] = true;
  // create s
  for(auto v : g[p]){
    if(visited[v.first]) continue;
    depth[v.first] = depth[p] + 1;
    for(int i = 0; i < 50; i++){
      if(s[p][i]) s[v.first][i] = true;
    }
    s[v.first][v.second] = true;
    dfs(v.first);
  }
}

int main(){
  int n; cin >> n;
  
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back({b - 1, i});
    g[b - 1].push_back({a - 1, i});
  }
  int m; cin >> m;
  vector<pair<int, int>> cs(m);
  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    cs[i] = mp(u - 1, v - 1);
  }

  ll ans = modpow(2, n - 1, 0);
  ll rsm = 0;

  depth[0] = 0;
  dfs(0);

  for(int i = 0; i < m; i++){
    if(depth[cs[i].first] > depth[cs[i].second]) swap(cs[i].first, cs[i].second);
  }

  for(int i = 1; i < (1 << m); i++){
    // 集合に含まれる条件を否定する
    vector<int> res(n, 0);
    int pc = 0;
    for(int j = 0; j < m; j++){
      if(i & (1 << j)){
        pc++;
        const pair<int, int>& p = cs[j];
        vector<bool> v(all(s[p.second]));
        for(int k = 0; k < n; k++) if(s[p.first][k]) v[k] = !v[k];

        for(int k = 0; k < n; k++){
          res[k] |= v[k];
        }
      }
    }

    int w = accumulate(all(res), 0);
    ll rev = modpow(2, n - 1 - w, 0);
    if(pc % 2){
      rsm += rev;
    }else{
      rsm -= rev;
    }
  }

  cout << ans - rsm << endl;
}