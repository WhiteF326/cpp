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
  ifstream ifs("24_large.txt");
  int n; ifs >> n;
  vector<vector<int>> g(n);
  vector<pair<int, int>> path(n - 1);
  for(int i = 0; i < n - 1; i++){
    int a, b; ifs >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
    path[i] = mp(a, b);
  }

  vector<int> depth(n, 0);
  vector<bool> visited(n, false);
  visited[0] = true;
  queue<int> q;
  q.push(0);

  while(!q.empty()){
    int dest = q.front();
    q.pop();

    for(int v : g[dest]){
      if(!visited[v]){
        visited[v] = true;
        depth[v] = depth[dest] + 1;
        q.push(v);
      }
    }
  }

  vector<ll> val(n, 0);

  int qu; ifs >> qu;
  query(qu){
    int t, e; ll x; ifs >> t >> e >> x;
    int from = path[e - 1].first, to = path[e - 1].second;
    if(t == 2){
      swap(from, to);
    }
    if(depth[from] < depth[to]){
      val[0] += x;
      val[to] -= x;
    }else{
      val[from] += x;
    }
  }

  q.push(0);
  fill(all(visited), false);
  visited[0] = true;
  while(!q.empty()){
    int dest = q.front();
    q.pop();

    for(int v : g[dest]){
      if(!visited[v]){
        visited[v] = true;
        val[v] += val[dest];
        q.push(v);
      }
    }
  }

  for(ll v : val) cout << v << endl;
}