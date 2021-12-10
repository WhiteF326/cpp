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


int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> g(m);
  vector<bool> used(m, false);

  int start = -1;
  for(int i = 0; i < n; i++){
    int k; cin >> k;
    vector<int> sl(k);
    for(int v = 0; v < k; v++){
      int l; cin >> l; l--;
      sl[v] = l;
      used[l] = true;
      if(start == -1) start = l;
    }
    for(int v = 0; v < k - 1; v++){
      g[sl[v]].push_back(sl[v + 1]);
      g[sl[v + 1]].push_back(sl[v]);
    }
  }

  vector<int> visited(m, false);
  visited[start] = true;
  queue<int> q;
  q.push(start);
  while(!q.empty()){
    int dest = q.front();
    q.pop();

    for(int v : g[dest]){
      if(visited[v]) continue;
      visited[v] = true;
      q.push(v);
    }
  }

  bool ans = true;
  for(int i = 0; i < m; i++){
    if(used[i] && !visited[i]) ans = false;
  }

  cout << (ans ? "YES" : "NO") << endl;
}