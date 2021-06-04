#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int h, w, n, m; cin >> h >> w >> n >> m;
  vector<vector<int>> stage(h, vector<int>(w, 0));
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    stage[a - 1][b - 1] = 1;
  }
  for(int i = 0; i < m; i++){
    int c, d; cin >> c >> d;
    stage[c - 1][d - 1] = -1;
  }
  vector<vector<bool>> ans(h, vector<bool>(w, false));
  vector<bool> vertical(w, false);
  for(int i = 0; i < h; i++){
    bool horizontal = false;
    for(int j = 0; j < w; j++){
      if(stage[i][j] == -1){
        horizontal = false;
        vertical[j] = false;
      }else if(stage[i][j] == 1){
        ans[i][j] = true;
        horizontal = true;
        vertical[j] = true;
      }else if(horizontal){
        ans[i][j] = true;
      }else if(vertical[j]){
        ans[i][j] = true;
      }
    }
  }
  for(int x = 0; x < w; x++) vertical[x] = false;
  for(int i = h - 1; i >= 0; i--){
    bool horizontal = false;
    for(int j = w - 1; j >= 0; j--){
      if(stage[i][j] == -1){
        horizontal = false;
        vertical[j] = false;
      }else if(stage[i][j] == 1){
        ans[i][j] = true;
        horizontal = true;
        vertical[j] = true;
      }else if(horizontal){
        ans[i][j] = true;
      }else if(vertical[j]){
        ans[i][j] = true;
      }
    }
  }
  int res = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      res += ans[i][j];
    }
  }
  cout << res << endl;
}