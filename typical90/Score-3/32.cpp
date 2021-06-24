#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
  // 隣接行列
  vector<vector<bool>> g(n, vector<bool>(n, true));
  int m; cin >> m;
  for(int i = 0; i < m; i++){
    int x, y; cin >> x >> y;
    x--, y--;
    g[x][y] = false, g[y][x] = false;
  }
  vector<int> perm(n);
  for(int i = 0; i < n; i++) perm[i] = i;
  int ans = INT_MAX;
  do{
    int res = 0, c = 1;
    for(int i = 0; i < n - 1; i++){
      if(g[perm[i]][perm[i + 1]]){
        res += a[perm[i]][i];
      }else{
        c = 0;
        break;
      }
    }
    if(c){
      res += a[perm[n - 1]][n - 1];
      ans = min(res, ans);
    }
  }while(next_permutation(perm.begin(), perm.end()));
  if(ans == INT_MAX) cout << -1 << endl;
  else cout << ans << endl;
}