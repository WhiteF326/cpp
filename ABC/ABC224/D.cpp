#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

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
  int m; cin >> m;

  auto tolist = [](vector<int> a){
    ll p = 0;
    for(int i = 0; i < 9; i++){
      p += modpow(10, i, 0) * (ll)a[i];
    }
    return p;
  };

  vector<int> xr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<ll> xt(0);

  do{
    xt.push_back(tolist(xr));
  }while(next_permutation(all(xr)));

  sort(all(xt));

  auto encode = [&](ll a){
    return lower_bound(all(xt), a) - xt.begin();
  };

  vector<pair<int, int>> s(m);
  for(int i = 0; i < m; i++){
    int l, r; cin >> l >> r;
    l = 9 - l, r = 9 - r;
    s[i] = mp(l, r);
  }

  vector<vector<int>> g(362880);

  vector<int> r = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int end = encode(tolist(r));
  do{
    int p = encode(tolist(r));
    for(int i = 0; i < m; i++){
      if(r[s[i].first] == 9){
        vector<int> tr(r);
        swap(tr[s[i].first], tr[s[i].second]);
        int q = encode(tolist(tr));
        g[p].push_back(q);
      }
    }
  }while(next_permutation(all(r)));

  vector<int> st(9, 9);
  for(int i = 1; i < 9; i++){
    int p; cin >> p;
    st[p - 1] = i;
  }

  int start = encode(tolist(st));

  queue<int> q;
  q.push(start);
  vector<bool> visited(362880, false);
  visited[start] = true;
  vector<int> depth(362880, INT_MAX);
  depth[start] = 0;

  while(!q.empty()){
    int dest = q.front();
    q.pop();

    for(int v : g[dest]){
      if(!visited[v]){
        depth[v] = depth[dest] + 1;
        visited[v] = true;
        q.push(v);
      }
    }
  }

  for(int v : g[encode(start)]) cout << xt[v] << " ";

  if(visited[end]){
    cout << depth[end] << endl;
  }else cout << -1 << endl;
}