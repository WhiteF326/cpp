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
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


vector<vector<int>> g(100000);
vector<ll> grundy(100000, 0);
vector<bool> visited(100000, false);

ll dfs(int p){
  visited[p] = true; 
  ll r = 0;

  for(int v : g[p]){
    if(visited[v]) continue;
    r ^= (dfs(v) + 1);
  }

  grundy[p] = r;
  return r;
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  for(int i = 0; i < n - 1; i++){
    int x, y; cin >> x >> y;
    g[x - 1].push_back(y - 1);
    g[y - 1].push_back(x - 1);
  }

  dfs(0);

  if(grundy[0]) cout << "Alice" << endl;
  else cout << "Bob" << endl;
}