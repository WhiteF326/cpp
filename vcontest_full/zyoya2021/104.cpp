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
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, q; cin >> n >> q;
  vector<vector<int>> g(n);
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }

  vector<ll> depth(n, 0);
  query(q){
    int p, x; cin >> p >> x;
    depth[p - 1] += x;
  }

  queue<int> d;
  d.push(0);
  vector<bool> visited(n, false);
  visited[0] = true;
  while(!d.empty()){
    int dest = d.front();
    d.pop();

    for(int v : g[dest]){
      if(visited[v]) continue;
      visited[v] = true;
      depth[v] += depth[dest];
      d.push(v);
    }
  }

  for(int i = 0; i < n; i++){
    cout << depth[i] << " ";
  }
  cout << endl;
}