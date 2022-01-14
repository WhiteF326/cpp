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
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int n;
vector<vector<int>> g(200000);
vector<int> si(200000, 0);
vector<ll> ans(200000, 0);

vector<bool> visited(200000, false);

void res(int p){
  visited[p] = true;
  int rev = 0;
  for(int v : g[p]){
    if(visited[v]) continue;
    res(v);
    rev += si[v];
  }
  rev++;
  si[p] = rev;
}
ll dp(int p, ll c){
  visited[p] = true;
  ans[p] = c;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  for(int v : g[p]){
    if(visited[v]) continue;
    q.push({si[v], v});
  }
  ll cur = c;
  while(!q.empty()){
    int dest = q.top().second;
    q.pop();

    cur = dp(dest, cur + 1LL);
  }
  return cur + 1LL;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  cin >> n;
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }

  int stt = 0;
  queue<int> q;
  q.push(0);
  vector<bool> vis(n, 0);
  vis[0] = true;
  vector<int> dep(n, 0);
  while(!q.empty()){
    int dest = q.front();
    q.pop();

    for(int v : g[dest]){
      if(vis[v]) continue;
      dep[v] = dep[dest] + 1;
      q.push(v);
      vis[v] = true;
    }
  }
  stt = max_element(all(dep)) - dep.begin();

  res(stt);
  fill(all(visited), false);
  dp(stt, 1LL);

  for(int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
  cout << *max_element(all(ans)) << endl;
}