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


const int s = 200000;
int n;
vector<vector<int>> g(s);
vector<bool> visited(s, 0);
vector<pair<int, int>> ans(s, {0, 0});
int stl = 1;

void dfs(int p){
  int l = INT_MAX, r = -1;
  for(int v : g[p]){
    if(visited[v]) continue;
    visited[v] = true;

    dfs(v);
    l = min(l, ans[v].first);
    r = max(r, ans[v].second);
  }

  if(l == INT_MAX){
    ans[p] = {stl, stl};
    stl++;
  }else{
    ans[p] = {l, r};
  }
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

  visited[0] = true;
  dfs(0);

  for(int i = 0; i < n; i++){
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}
