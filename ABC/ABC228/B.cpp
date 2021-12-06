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
  int n, x; cin >> n >> x;
  vector<vector<int>> g(n);
  for(int i = 0; i < n; i++){
    int v; cin >> v;
    g[i].push_back(v - 1);
  }

  queue<int> q;
  q.push(x - 1);
  vector<int> visited(n, false);
  visited[x - 1] = true;
  while(!q.empty()){
    int dest = q.front();
    q.pop();

    for(int v : g[dest]){
      if(!visited[v]){
        q.push(v);
        visited[v] = true;
      }
    }
  }

  cout << accumulate(all(visited), 0) << endl;
}