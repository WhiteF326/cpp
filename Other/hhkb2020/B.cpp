#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int h, w; cin >> h >> w;
  vector<vector<bool>> stage(h + 1, vector<bool>(w + 1, false));
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      stage[i][j] = s.substr(j, 1) == ".";
    }
  }
  int ans = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      ans += stage[i][j] & stage[i][j + 1];
      ans += stage[i][j] & stage[i + 1][j];
    }
  }
  cout << ans << endl;
}