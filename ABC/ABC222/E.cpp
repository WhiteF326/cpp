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


const ll modv = 998244353;

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

int main(){
  int n, m, k; cin >> n >> m >> k;
  vector<int> path(m);
  aryin(path, m);

  vector<vector<int>> g(n);
  
  for(int i = 0; i < n - 1; i++){
    int u, v; cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }

  map<pair<int, int>, int> roots;
  // bfs して通った回数を数える
  for(int i = 0; i < m - 1; i++){
    queue<int> q;
    q.push(path[i] - 1);
    vector<int> before(n, -1);
    vector<bool> visited(n, false);
    visited[path[i] - 1] = true;

    while(!q.empty()){
      int dest = q.front();
      q.pop();

      for(int v : g[dest]){
        if(!visited[v]){
          before[v] = dest;
          visited[v] = true;
          q.push(v);
        }
      }
    }

    // 経路復元
    int cur = path[i + 1] - 1;
    while(before[cur] != -1){
      // cur ~ before を +1
      int l = min(cur, before[cur]);
      int r = max(cur, before[cur]);
      roots[mp(l, r)]++;
      cur = before[cur];
    }
  }

  vector<int> counts(0);
  for(auto p : roots) counts.push_back(p.second);
  int x = counts.size();
  int sum = accumulate(all(counts), 0) + k;
  int mid = sum / 2;
  int lm;
  if(sum % 2){
    cout << 0 << endl;
    return 0;
  }else{
    lm = mid - k;
  }

  ll last = n - 1 - x;

  // 振り分ける dp
  vector<vector<ll>> dp(x + 1, vector<ll>(100001, 0));
  dp[0][0] = 1;
  for(int i = 0; i < x; i++){
    for(int j = 0; j <= 100000; j++){
      if(dp[i][j]){
        // 選ぶ
        dp[i + 1][j + counts[i]]
          = (dp[i + 1][j + counts[i]] + dp[i][j]) % modv;
        // 選ばない
        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % modv;
      }
    }
  }

  ll ans = 0;
  if(lm >= 0 && lm <= 100000) ans += dp[x][lm];
  ans = (ans * modpow(2, last, modv)) % modv;

  cout << ans % modv << endl;
}