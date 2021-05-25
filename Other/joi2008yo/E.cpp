#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int r, c; cin >> r >> c;
  vector<vector<int>> stage(r, vector<int>(c, 0));
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++) cin >> stage[i][j];
  }
  int ans = 0;
  // rを全探索してみる
  for(int i = 0; i < (1 << r); i++){
    // 実際に裏返す
    for(int j = 0; j < r; j++){
      if(i & (1 << j)){
        for(int k = 0; k < c; k++){
          stage[j][k] = (stage[j][k] + 1) % 2;
        }
      }
    }
    // 解を求める
    int tr = 0;
    for(int j = 0; j < c; j++){
      int res = 0;
      for(int k = 0; k < r; k++){
        res += stage[k][j];
      }
      res = max(res, r - res);
      tr += res;
    }
    ans = max(tr, ans);
    // 元に戻す
    for(int j = 0; j < r; j++){
      if(i & (1 << j)){
        for(int k = 0; k < c; k++){
          stage[j][k] = (stage[j][k] + 1) % 2;
        }
      }
    }
  }
  cout << ans << endl;
}