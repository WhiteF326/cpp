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

const ll modv = 1000000007;
const ll d = 500000004;

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

int n;
ll ans = 0;
vector<vector<pair<int, ll>>> g(200000);
vector<bool> vis(200000, false);
vector<int> bitlist(61, 0);

void rec(int p){
  for(int i = 0; i < 60; i++){
    ans += (modpow(2, i, modv) * bitlist[i]) % modv;
    ans %= modv;
  }
  ans %= modv;
  for(auto v : g[p]){
    if(vis[v.first]) continue;
    int next = v.first;
    for(int i = 0; i <= 60; i++){
      if(v.second & (1LL << i)){
        bitlist[i] = n - bitlist[i];
      }
    }
    
    vis[v.first] = true;
    rec(next);
    for(int i = 0; i <= 60; i++){
      if(v.second & (1LL << i)){
        bitlist[i] = n - bitlist[i];
      }
    }
  }
};

int main(){
  cin >> n;
  for(int i = 0; i < n - 1; i++){
    int u, v; cin >> u >> v;
    ll w; cin >> w;
    u--, v--;
    g[u].push_back(mp(v, w));
    g[v].push_back(mp(u, w));
  }

  queue<int> q;
  q.push(0);
  vector<bool> visited(n, false);
  visited[0] = true;
  vector<ll> dist(n, 0);
  while(!q.empty()){
    int dest = q.front();
    q.pop();

    for(auto v : g[dest]){
      int next = v.first;
      if(!visited[next]){
        visited[next] = true;
        dist[next] = dist[dest] ^ v.second;
        q.push(next);
      }
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j <= 60; j++){
      if(dist[i] & (1LL << j)) bitlist[j]++;
    }
  }

  vis[0] = true;
  rec(0);

  ans = (ans * d) % modv;

  cout << ans << endl;
}