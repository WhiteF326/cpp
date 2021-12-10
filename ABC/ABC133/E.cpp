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


const ll modv = 1000000007;

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

ll modinv(ll x, ll modv){
  ll b = modv, u = 1, v = 0;
  while(b){
    ll t = x / b;
    x -= t * b;
    swap(x, b);
    u -= t *v;
    swap(u, v);
  }
  u %= modv;
  if(u < 0) u += modv;
  return u;
}

int main(){
  int n, k; cin >> n >> k;
  vector<vector<int>> g(n);
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }

  // 1 を根として各頂点ごとの直子の個数
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

  // 階乗の表
  vector<ll> fact(k + 1, 0);
  fact[0] = 1, fact[1] = 1;
  for(int i = 2; i <= k; i++) fact[i] = (fact[i - 1] * i) % modv;
  // 逆元の表
  vector<ll> invs(k + 1, 0);
  for(int i = 0; i <= k; i++) invs[i] = modinv(fact[i], modv);

  ll ans = k;
  q.push(0);
  for(int i = 1; i < n; i++) visited[i] = false;
  while(!q.empty()){
    int dest = q.front();
    q.pop();

    // 求める
    if(c[dest]){
      ll color = k - min(2, depth[dest] + 1);
      if(color < c[dest]){
        ans = 0;
      }else{
        ans = (ans * ((fact[color] * invs[color - c[dest]]) % modv)) % modv;
      }
    }
    

    for(int v : g[dest]){
      if(visited[v]) continue;
      q.push(v);
      visited[v] = true;
    }
  }

  cout << ans << endl;
}