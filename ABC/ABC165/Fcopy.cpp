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
#define aryin(a, n) for(int i = 0; i < n; i++) ifs >> a[i];


int n;
vector<ll> a(200000);
vector<vector<int>> g(200000);
vector<bool> visited(200000, 0);
vector<int> ans(200000, 0);
// 長さ i における LIS の末尾の最小値
vector<int> dp(200000, INT_MAX);

ofstream ofs("test.txt");

void dfs(int p){
  if(visited[p]) return;
  visited[p] = true;

  ans[p] = (lower_bound(all(dp), INT_MAX) - dp.begin()) + 1;

  ofs << ans[p] << endl;

  int rs = lower_bound(all(dp), a[p]) - dp.begin();

  int back = dp[rs];
  dp[rs] = a[p];
  for(int v : g[p]){
    dfs(v);
  }
  dp[rs] = back;
}

int main(){
  ifstream ifs("caterpillar_01.txt");
  ifs >> n;
  aryin(a, n);
  for(int i = 0; i < n - 1; i++){
    int u, v; ifs >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }

  dfs(0);

  cout << "test" << endl;

  for(int i = 0; i < n; i++) ofs << ans[i] << endl;
}