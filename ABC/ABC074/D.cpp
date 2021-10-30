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


struct dsq{
  int n;
  vector<int> parent;
  vector<deque<int>> q;

  dsq(int n){
    this->n = n;
    parent.resize(n);
    for(int &a : parent) a = -1;
    q.resize(n);
    for(int i = 0; i < n; i++) q[i].push_back(i);
  }

  void merge(int l, int r){
    int lp = getRoot(l);
    int rp = getRoot(r);
    if(lp == rp) return;
    if(q[lp].size() >= q[rp].size()){
      parent[rp] = lp;
      while(!q[rp].empty()){
        q[lp].push_back(q[rp].front());
        q[rp].pop_front();
      }
    }else{
      parent[lp] = rp;
      while(!q[lp].empty()){
        q[rp].push_back(q[lp].front());
        q[lp].pop_front();
      }
    }
  }

  vector<int> get(int p){
    int pt = getRoot(p);
    vector<int> res(all(q[pt]));
    return res;
  }

  int getParent(int p){
    return parent[p];
  }

  int getRoot(int p){
    int pt = p;
    while(parent[pt] != -1) pt = this->getParent(pt);
    return pt;
  }
};


int main(){
  int n; cin >> n;
  vector<vector<ll>> a(n, vector<ll>(n, 0));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) cin >> a[i][j];
  }
  
  vector<pair<ll, int>> g;

  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      g.push_back({a[i][j], i * n + j});
    }
  }

  // validate
  vector<vector<ll>> test(all(a));
  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        test[i][j] = min(test[i][j], test[i][k] + test[k][j]);
      }
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(test[i][j] < a[i][j]){
        cout << -1 << endl;
        return 0;
      }
    }
  }

  sort(all(g));

  dsq d(n);

  // todo
  vector<vector<ll>> cur(n, vector<ll>(n, LLONG_MAX / 2));
  for(int i = 0; i < n; i++) cur[i][i] = 0;

  ll ans = 0;
  for(auto p : g){
    int l = p.second / n, r = p.second % n;
    ll w = p.first;

    if(cur[l][r] > w){
      cur[l][r] = w;
      cur[r][l] = w;
      ans += w;
    }

    // l -> r
    for(int v : d.get(r)){
      if(cur[l][v] > w + cur[v][r]){
        cur[l][v] = w + cur[v][r];
        cur[v][l] = w + cur[v][r];
      }
    }
    // r -> l
    for(int v : d.get(l)){
      if(cur[v][r] > w + cur[l][v]){
        cur[v][r] = w + cur[l][v];
        cur[r][v] = w + cur[l][v];
      }
    }

    d.merge(l, r);

    // for(auto dq : cur){
    //   for(auto v : dq){
    //     cout << v << " ";
    //   }cout << endl;
    // }
  }

  cout << ans << endl;
}