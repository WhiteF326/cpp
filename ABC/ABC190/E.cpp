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

const int infl = INT_MAX;


int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n);

  dsu d(n);
  query(m){
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
    d.merge(a, b);
  }
  int k; cin >> k;
  vector<int> c(k); aryin(c, k);
  for(int i = 0; i < k; i++) c[i]--;

  for(int i = 0; i < k - 1; i++){
    if(!d.same(c[i], c[i + 1])){
      cout << -1 << endl;
      return 0;
    }
  }

  // k の各頂点から bfs
  int ans = infl;
  vector<vector<int>> depth(k, vector<int>(n, infl));
  for(int i = 0; i < k; i++){
    int root = c[i];
    queue<int> q;
    q.push(root);
    depth[i][root] = 0;
    vector<bool> visited(n, false);
    visited[root] = true;
    while(!q.empty()){
      int dest = q.front();
      q.pop();

      for(int v : g[dest]){
        if(visited[v]) continue;
        depth[i][v] = depth[i][dest] + 1;
        visited[v] = true;
        q.push(v);
      }
    }
  }

  // dp[i][bit][j] = i + 1 個の魔法石を揃えた、魔法石の集合が bitx、最後の魔法石が j
  vector<vector<vector<int>>> dp(k, vector<vector<int>>(1 << k, vector<int>(k, infl)));
  for(int i = 0; i < k; i++){
    dp[0][1 << i][i] = 1;
  }
  for(int i = 0; i < k - 1; i++){
    for(int j = 0; j < (1 << k); j++){
      for(int l = 0; l < k; l++){
        if(dp[i][j][l] == infl) continue;
        for(int ch = 0; ch < k; ch++){
          // もう選んだ魔法石である
          if(j & (1 << ch)) continue;
          // 選ぶ
          // cout << i + 1 << " " << (j | (1 << ch)) << " " << ch << " " << dp[i][j][l] + depth[l][c[ch]] << endl;
          chmin(dp[i + 1][j | (1 << ch)][ch], dp[i][j][l] + depth[l][c[ch]]);
        }
      }
    }
  }

  for(int i = 0; i < k; i++){
    chmin(ans, dp[k - 1][(1 << k) - 1][i]);
  }
  cout << ans << endl;
}