#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int h, w; cin >> h >> w;
  vector<vector<bool>> stage(h, vector<bool>(w, false));
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      stage[i][j] = s.substr(j, 1) == "#";
    }
  }
  int ans = 0;
  for(int i = 0; i < h - 1; i++){
    for(int j = 0; j < w - 1; j++){
      int flg = 0;
      for(int y = 0; y < 2; y++){
        for(int x = 0; x < 2; x++){
          flg += stage[i + y][j + x];
        }
      }
      ans += flg % 2;
    }
  }
  cout << ans << endl;
}
