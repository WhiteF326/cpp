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

vector<vector<int>> way = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int main(){
  int h, w; cin >> h >> w;
  vector<vector<int>> stage(h, vector<int>(w, 0));
  map<int, vector<int>> tp;
  auto pos = [&](int y, int x){return y * w + x;};
  int sy, sx, gy, gx;
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      if(s[j] == '#') stage[i][j] = -1;
      else if(s[j] == 'S') sy = i, sx = j;
      else if(s[j] == 'G') gy = i, gx = j;
      else if(s[j] >= 'a'){
        stage[i][j] = s[j];
        tp[s[j]].push_back(pos(i, j));
      }
    }
  }

  map<int, int> tpused;
  queue<int> q;
  q.push(pos(sy, sx));
  vector<vector<int>> depth(h, vector<int>(w, INT_MAX));
  depth[sy][sx] = 0;
  vector<vector<bool>> visited(h, vector<bool>(w, false));
  visited[sy][sx] = true;
  vector<vector<bool>> see(h, vector<bool>(w, false));

  while(!q.empty()){
    int dest = q.front();
    q.pop();
    int cy = dest / w, cx = dest % w;
    see[cy][cx] = true;

    if(stage[cy][cx] >= 1 && !tpused[stage[cy][cx]]){
      int tpn = stage[cy][cx];
      for(int tpd : tp[tpn]){
        int ty = tpd / w, tx = tpd % w;
        if(!visited[ty][tx]){
          chmin(depth[ty][tx], depth[cy][cx] + 1);
          visited[ty][tx] = true;
          q.push(tpd);
        }
      }
      tpused[tpn] = true;
    }

    for(int i = 0; i < 4; i++){
      int dy = cy + way[i][0], dx = cx + way[i][1];
      if(dy < 0 || dy >= h || dx < 0 || dx >= w) continue;

      if(!visited[dy][dx] && stage[dy][dx] >= 0){
        chmin(depth[dy][dx], depth[cy][cx] + 1);
        visited[dy][dx] = true;
        q.push(pos(dy, dx));
      }
    }
  }

  if(depth[gy][gx] == INT_MAX) cout << -1 << endl;
  else cout << depth[gy][gx] << endl;
}