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
vector<ll> a(200000);
vector<vector<int>> g(200000);
vector<bool> visited(200000, 0);
vector<int> ans(200000, 0);
// 長さ i における LIS の末尾の最小値
vector<int> dp(200000, INT_MAX);

void dfs(int p){
  if(visited[p]) return;
  visited[p] = true;

  int rs = lower_bound(all(dp), a[p]) - dp.begin();

  ans[p] = rs + 1;

  int back = dp[rs];
  dp[rs] = a[p];
  for(int v : g[p]){
    dfs(v);
  }
  dp[rs] = back;
}

int main(){
  cin >> n;
  aryin(a, n);
  for(int i = 0; i < n - 1; i++){
    int u, v; cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }

  dfs(0);

  for(int i = 0; i < n; i++) cout << ans[i] << endl;
}