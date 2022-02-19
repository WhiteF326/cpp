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


#define mint modint1000000007

const int MAX = 102202;
const int MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
ll C(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll P(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return (fac[n] * finv[n - k]) % MOD;
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  COMinit();
  
  int n, k; cin >> n >> k;
  vector<vector<int>> g(n);
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }

  vector<int> c(n, 0);
  vector<bool> visited(n, false);
  visited[0] = true;
  vector<int> depth(n, INT_MAX);
  depth[0] = 0;
  queue<int> q;
  q.push(0);

  while(!q.empty()){
    int dest = q.front();
    q.pop();

    for(int v : g[dest]){
      if(visited[v]) continue;
      c[dest]++;
      visited[v] = true;
      depth[v] = depth[dest] + 1;
      q.push(v);
    }
  }

  mint ans = k;
  q.push(0);
  fill(visited.begin() + 1, visited.end(), false);
  while(!q.empty()){
    int dest = q.front();
    q.pop();

    if(c[dest]){
      ll cx = k - min(2, depth[dest] + 1);
      if(cx < c[dest]){
        ans = 0;
      }else{
        ans *= P(cx, c[dest]);
      }
    }

    for(int v : g[dest]){
      if(visited[v]) continue;
      visited[v] = true;
      q.push(v);
    }
  }

  cout << ans.val() << endl;
}
