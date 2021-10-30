#include <bits/stdc++.h>
using namespace std;

#define const constexpr
using ll = long long;
#define query(t) for(int _ = 0; _ < t; _++)


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
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> in(n, 0);
  query(m){
    int l, r; cin >> l >> r;
    l--, r--;
    g[l].push_back(r);
    in[r]++;
  }

  vector<int> tps(0);
  queue<int> q;
  for(int i = 0; i < n; i++){
    if(!in[i]) q.push(i);
  }
  while(!q.empty()){
    int dest = q.front();
    q.pop();
    tps.emplace_back(dest);
    for(int v : g[dest]){
      in[v]--;
      if(!in[v]) q.push(v);
    }
  }

  vector<vector<ll>> dp(n, vector<ll>(n + 1, 0));
  dp[0][1] = 1;
  for(int i : tps){
    for(int j = 0; j < n; j++){
      if(!dp[i][j]) continue;
      
      for(int v : g[i]){
        dp[v][j + 1] += dp[i][j];
      }
    }
  }

  ll ans = 0;
  for(int i = 0; i <= n; i++){
    ans = (ans + (2LL * modpow(2, n - i, modv) * dp[n - 1][i]) % modv) % modv;
  }
  cout << ans << endl;
}