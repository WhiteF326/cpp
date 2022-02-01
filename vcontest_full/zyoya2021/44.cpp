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
  
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back(b - 1);
  }

  int ans = 0;
  for(int i = 0; i < n; i++){
    queue<int> q;
    q.push(i);
    vector<int> visited(n, false);
    visited[i] = true;

    while(!q.empty()){
      int dest = q.front();
      q.pop();
      ans++;

      for(int v : g[dest]){
        if(visited[v]) continue;
        q.push(v);
        visited[v] = true;
      }
    }
  }

  cout << ans << endl;
}