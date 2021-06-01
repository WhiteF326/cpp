#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  vector<int> h(n);
  for(int i = 0; i < n; i++) cin >> h[i];
  vector<vector<int>> g(n, vector<int>(0));
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    bool flg = true;
    for(int j = 0; j < g[i].size(); j++){
      if(h[i] <= h[g[i][j]]) flg = false;
    }
    ans += flg;
  }
  cout << ans << endl;
}