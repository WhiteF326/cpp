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
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


const int LM = 20;
vector<vector<int>> mx(100000, vector<int>(20, -1));
vector<bool> visited(100000, 0);
int n;
vector<int> x(100000);
vector<vector<int>> g(100000);
void dfs(int p){
  vector<int> rq(20, -1);
  for(int v : g[p]){
    if(visited[v]) continue;
    visited[v] = true;
    dfs(v);
    for(int i = 0; i < LM; i++){
      rq.emplace_back(mx[v][i]);
    }
  }
  rq.emplace_back(x[p]);
  sort(all(rq), greater<int>());
  for(int i = 0; i < LM; i++){
    mx[p][i] = rq[i];
  }
}


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int q; cin >> n >> q;
  aryin(x, n);

  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }

  visited[0] = true;
  dfs(0);

  query(q){
    int v, k; cin >> v >> k;
    cout << mx[v - 1][k - 1] << endl;
  }
}
