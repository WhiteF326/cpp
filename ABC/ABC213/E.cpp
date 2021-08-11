#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;

int h, w;
vector<vector<int>> stage(500, vector<int>(500, 0));
vector<vector<bool>> visited(500, vector<bool>(500, false));
int ans = INT_MAX;
vector<vector<int>> way = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
vector<vector<vector<int>>> dpos = {
  { {-1, -1}, {-1, 0}, {0, -1} },
  { {-1, 0}, {-1, 1}, {0, 1} },
  { {0, -1}, {1, -1}, {1, 0} },
  { {0, 1}, {1, 0}, {1, 1} }
};

void dfs(int y, int x, int dest){
  visited[y][x] = true;
  if(y == h - 1 && x == w - 1){
    ans = min(ans, dest);
    return;
  }
  bool stop = true;
  for(int i = 0; i < 4; i++){
    int dy = y + way[i][0], dx = x + way[i][1];
    if(dy >= h || dy < 0 || dx >= w || dx < 0) continue;
    if(stage[dy][dx] == 0 && !visited[dy][dx]){
      stop = false;
      dfs(dy, dx, dest);
    }
  }
  if(stop){
    for(int i = 0; i < 4; i++){
      int dy = y + way[i][0], dx = x + way[i][1];
      if(dy >= h || dy < 0 || dx >= w || dx < 0) continue;
      if(stage[dy][dx] == 1){
        for(int j = 0; j < 4; j++){
          vector<int> def(4);
          bool ok = true;
          for(int k = 0; k < 3; k++){
            int ty = dy + dpos[j][k][0], tx = dy + dpos[j][k][1];
            if(ty >= h || ty < 0 || tx >= w || tx < 0){
              ok = false;
              break;
            }
            def[k] = stage[ty][tx];
          }
          if(ok){
            def[3] = stage[dx][dy];
            stage[dx][dy] = 0;
            for(int k = 0; k < 3; k++){
              stage[dy + dpos[j][k][0]][dy + dpos[j][k][1]] = 0;
            }
            dfs(y, x, dest + 1);
            for(int k = 0; k < 3; k++){
              stage[dy + dpos[j][k][0]][dy + dpos[j][k][1]] = def[k];
            }
            stage[dx][dy] = def[3];
          }
        }
      }
    }
  }
}

int main(){
  cin >> h >> w;
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      stage[i][j] = s[j] == '#';
    }
  }
  dfs(0, 0, 0);
  cout << ans << endl;
}