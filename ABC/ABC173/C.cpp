#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

constexpr int modv = 1000000007;

int main(){
  int h, w, k; cin >> h >> w >> k;
  vector<vector<int>> c(h, vector<int>(w, 0));
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      if(s[j] == '#') c[i][j] = 1;
    }
  }

  int ans = 0;
  for(int i = 0; i < (1 << h); i++){
    for(int j = 0; j < (1 << w); j++){
      vector<vector<int>> stage(c);
      for(int r = 0; r < h; r++){
        if(i & (1 << r)){
          for(int c = 0; c < w; c++){
            stage[r][c] = 0;
          }
        }
      }
      for(int c = 0; c < w; c++){
        if(j & (1 << c)){
          for(int r = 0; r < h; r++){
            stage[r][c] = 0;
          }
        }
      }
      int res = 0;
      for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
          res += stage[y][x];
        }
      }
      ans += (res == k);
    }
  }
  cout << ans << endl;
}