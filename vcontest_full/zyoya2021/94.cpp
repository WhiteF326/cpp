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


int n;
vector<vector<pair<int, int>>> g(100000);
vector<int> ans(100000, 0);

void dfs(int cur, int par, int col){
  set<int> used;
  used.insert(col);
  int color = 1;
  for(auto p : g[cur]){
    if(p.first != par){
      while(used.find(color) != used.end()) color++;
      ans[p.second] = color;
      dfs(p.first, cur, color);
      color++;
    }
  }
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back({b - 1, i});
    g[b - 1].push_back({a - 1, i});
  }

  dfs(0, -1, 0);
  int mx = 0;
  for(int i = 0; i < n; i++) mx = max(mx, (int)g[i].size());
  cout << mx << endl;
  for(int i = 0; i < n - 1; i++){
    cout << ans[i] << endl;
  }
}