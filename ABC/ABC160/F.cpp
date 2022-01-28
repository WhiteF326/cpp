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


int n;
vector<vector<int>> g(200000);
vector<bool> visited(200000, 0);
#define mint modint1000000007
vector<mint> dp(200000, 0);
vector<int> sx(200000, 0);

vector<mint> ans(200000, 0);

#define mx 2000050
const ll modv = 1000000007;

// binomial coefficient
ll fac[mx], finv[mx], inv[mx];

void cinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < mx; i++){
    fac[i] = fac[i - 1] * i % modv;
    inv[i] = modv - inv[modv%i] * (modv / i) % modv;
    finv[i] = finv[i - 1] * inv[i] % modv;
  }
}

ll binom(int n, int k){
  if (n < k) swap(n, k);
  // if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % modv) % modv;
}
// thanks for drken

void tree_dp(int p){
  visited[p] = true;
  int res = 0;
  dp[p] = 1;
  for(int v : g[p]){
    if(visited[v]) continue;
    tree_dp(v);
    res += sx[v];
    ll bc = binom(res, sx[v]);
    dp[p] *= dp[v] * bc;
  }
  sx[p] = res + 1;
}

void dfs(int p){
  ans[p] = dp[p];
  visited[p] = true;

  for(int v : g[p]){
    if(visited[v]) continue;

    int par = sx[p];
    int ver = sx[v];
    mint back = dp[v];
    mint left = dp[p];

    // 辺を切る
    sx[p] -= sx[v];
    dp[p] /= dp[v] * binom(n - 1, sx[v]);

    // 辺を貼る
    sx[v] += sx[p];
    dp[v] *= dp[p] * binom(n - 1, sx[p]);

    // 再帰
    dfs(v);

    // 辺を切る
    dp[v] = back;
    sx[v] = ver;

    // 辺を貼る
    dp[p] = left;
    sx[p] = par;
  }
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  cin >> n;
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }

  cinit();

  tree_dp(0);

  fill(all(visited), false);
  dfs(0);

  for(int i = 0; i < n; i++){
    cout << ans[i].val() << endl;
  }
}