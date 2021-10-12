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

const int infl = 10000000;

int n;
vector<vector<int>> g(200000);
vector<ll> depth(200000, 0);
vector<ll> chl(200000, 0);
ll ans;

vector<ll> anslist(200000);

void dfs(int ptr, int p){
  for(int v : g[ptr]){
    if(p == v) continue;
    depth[v] = depth[ptr] + 1;
    dfs(v, ptr);
  }
  chl[ptr] = 1;
  for(int v : g[ptr]){
    if(p == v) continue;
    chl[ptr] += chl[v];
  }
}

void tdp(int ptr, int p){
  anslist[ptr] = ans;
  for(int v : g[ptr]){
    if(p == v) continue;
    // 切られる方
    ans += (n - chl[v]);
    // 切る方
    ans -= chl[v];
    // 再計算
    int defc = chl[ptr];
    chl[ptr] = n - chl[v];
    // 再帰
    tdp(v, ptr);
    // 戻り
    ans -= (n - chl[v]);
    ans += chl[v];
    chl[ptr] = defc;
  }
}

int main(){
  cin >> n;

  for(int i = 0; i < n - 1; i++){
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(0, -1);

  ans = accumulate(all(depth), 0LL);

  tdp(0, -1);

  for(int i = 0; i < n; i++){
    cout << anslist[i] << endl;
  }
}