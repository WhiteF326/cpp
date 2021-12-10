#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

using ll = long long;

vector<bool> visited(50000, false);
vector<int> parent(50000, -1);
vector<vector<pair<int, ll>>> g(50000);

void dfs(int p, vector<ll>& f){
  if(visited[p]) return;
  visited[p] = true;

  for(auto v : g[p]){
    if(visited[v.first]) continue;
    parent[v.first] = p;
    dfs(v.first, f);
    f[p] ^= f[v.first];
    f[p] ^= v.second;
  }
}

int main(){
  int n; cin >> n;
  assert(n <= 50000);

  dsu d(n);
  int s = 0;
  
  for(int i = 0; i < n - 1; i++){
    int l, r; cin >> l >> r;
    assert(1 <= l && l <= n && 1 <= r && r <= n);
    ll a; cin >> a;
    assert(a <= 1000000000000000000);
    g[l - 1].push_back({r - 1, a});
    g[r - 1].push_back({l - 1, a});
    d.merge(l - 1, r - 1);
  }

  assert(d.groups().size() == 1);
  cout << s << endl;

  vector<ll> f(n, 0);

  dfs(0, f);

  for(int v : f) cout << v << endl;
  
  queue<ll> anslist;

  int q; cin >> q;
  assert(q <= 50000);
  for(int i = 0; i < q; i++){
    int t, x, y; cin >> t >> x >> y;
    assert(t == 1 || t == 2);
    if(t == 1){
      assert(2 <= x && x <= n);
      assert(1 <= y && y <= n);
      assert(x != y);
      x--, y--;
      f[parent[x]] ^= f[x];
      f[y] ^= f[x];
      parent[x] = y;
    }else{
      assert(1 <= x && x <= n);
      assert(y == 0);
      anslist.push(f[x - 1]);
    }
  }

  while(!anslist.empty()){
    cout << anslist.front() << endl;
    anslist.pop();
  }

  return 0;
}