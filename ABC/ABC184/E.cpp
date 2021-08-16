#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

int main(){
  int h, w; cin >> h >> w;
  vector<vector<int>> stage(h, vector<int>(w, -1));
  vector<vector<pair<int, int>>> tp(26, vector<pair<int, int>>(0));
  int sy, sx, gy, gx;
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      switch(s[j]){
        case 'S':
          sy = i, sx = j;
          stage[i][j] = 0;
          break;
        case 'G':
          gy = i, gx = j;
          stage[i][j] = 0;
          break;
        case '.':
          stage[i][j] = 0;
          break;
        case '#':
          break;
        default:
          tp[s[j] - 'a'].emplace_back(mp(i, j));
          stage[i][j] = s[j] - 'a' + 1;
          break;
      }
    }
  }
  
}