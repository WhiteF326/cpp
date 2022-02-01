#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)


struct Edge{
  int from;
  int to;
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<vector<int>> g(n);
  vector<Edge> e(n - 1);
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
    e[i] = {a - 1, b - 1};
  }
  priority_queue<int> pq;
  for(int i = 0; i < n; i++){
    int c; cin >> c;
    pq.push(c);
  }

  queue<int> q;
  q.push(0);
  vector<int> s(n, 0);
  vector<bool> visited(n, false);
  visited[0] = true;

  while(!q.empty()){
    int dest = q.front();
    q.pop();

    s[dest] = pq.top();
    pq.pop();

    for(int v : g[dest]){
      if(visited[v]) continue;
      visited[v] = true;
      q.push(v);
    }
  }

  int ans = 0;
  for(int i = 0; i < n - 1; i++){
    ans += min(s[e[i].from], s[e[i].to]);
  }
  cout << ans << endl;
  for(int i = 0; i < n; i++) cout << s[i] << " ";
  cout << endl;
}