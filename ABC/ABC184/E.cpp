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
  // initialize
  int h, w; cin >> h >> w;
  vector<vector<int>> stage(h, vector<int>(w, -1));
  vector<vector<pair<int, int>>> tp(27, vector<pair<int, int>>(0));
  int sy, sx, gy, gx;
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      if(s[j] == '#') continue;
      else if(s[j] >= 'a' && s[j] <= 'z'){
        tp[s[j] - 'a' + 1].push_back(mp(i, j));
        stage[i][j] = s[j] - 'a' + 1;
      }else{
        stage[i][j] = 0;
        if(s[j] == 'S') sy = i, sx = j;
        if(s[j] == 'G') gy = i, gx = j;
      }
    }
  }
  auto pos = [&](int y, int x) {return y * w + x;};
  
  // first bfs
  queue<int> q;
  q.push(pos(gy, gx));
  vector<vector<int>> depth(h, vector<int>(w, INT_MAX));
  depth[sy][sx] = 0;
  vector<vector<bool>> visited(h, vector<bool>(w, false));
  visited[sy][sx] = true;
  vector<bool> reachlist(27, false);
  while(!q.empty()){
    int dest = q.front();
    int cy = dest / w, cx = dest % w;
    q.pop();
    for(int i = 0; i < 4; i++){
      int dy = cy + way[i][0], dx = cx + way[i][1];
      if(dy >= h || dy < 0 || dx >= w || dx < 0) continue;
      if(stage[dy][dx] < 0) continue;
      if(stage[dy][dx] > 0){
        reachlist[stage[dy][dx]] = true;
      }
      if(!visited[dy][dx]){
        depth[dy][dx] = depth[cy][cx] + 1;
        visited[dy][dx] = true;
        q.push(pos(dy, dx));
      }
    }
  }

  // fix teleporter
  vector<pair<int, int>> dtp(27);
  for(int i = 1; i <= 26; i++){
    if(!reachlist[i]) continue;
    auto tplist = tp[i];
    int nearest = INT_MAX;
    for(auto stp : tplist){
      int tpy = stp.first, tpx = stp.second;
      if(depth[tpy][tpx] < nearest){
        nearest = depth[tpy][tpx];
        dtp[i] = mp(tpy, tpx);
      }
    }
  }

  // second bfs
  q.push(pos(sy, sx));
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      depth[i][j] = INT_MAX;
      visited[i][j] = false;
    }
  }
  depth[sy][sx] = 0;
  visited[sy][sx] = true;
  while(!q.empty()){
    int dest = q.front();
    int cy = dest / w, cx = dest % w;
    q.pop();
    if(stage[cy][cx] > 0){
      // tp
      int tpn = stage[cy][cx];
      int dy = dtp[tpn].first, dx = dtp[tpn].second;
      if(!visited[dy][dx]){
        depth[dy][dx] = depth[cy][cx] + 1;
        visited[dy][dx] = true;
        q.push(pos(dy, dx));
      }
    }
    for(int i = 0; i < 4; i++){
      int dy = cy + way[i][0], dx = cx + way[i][1];
      if(dy >= h || dy < 0 || dx >= w || dx < 0) continue;
      if(stage[dy][dx] < 0) continue;
      if(!visited[dy][dx]){
        depth[dy][dx] = depth[cy][cx] + 1;
        visited[dy][dx] = true;
        q.push(pos(dy, dx));
      }
    }
  }

  if(depth[gy][gx] == INT_MAX){
    cout << "-1" << endl;
  }else cout << depth[gy][gx] << endl;
}