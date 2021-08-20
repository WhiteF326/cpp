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
#define infi 1000000000

vector<vector<int>> way = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int main(){
  int h, w; cin >> h >> w;
  int sy, sx, gy, gx; cin >> sy >> sx >> gy >> gx;
  sy--, sx--, gy--, gx--;
  vector<vector<int>> stage(h, vector<int>(w, 0));
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++) stage[i][j] = s[j] == '#';
  }
  
  // (y, x)
  deque<pair<int, int>> deq;
  deq.push_front(mp(sy, sx));
  vector<vector<int>> depth(h, vector<int>(w, infi));
  depth[sy][sx] = 0;

  while(!deq.empty()){
    auto dest = deq.front();
    deq.pop_front();
    int cy = dest.first, cx = dest.second;

    for(int i = 0; i < 4; i++){
      int dy = way[i][0], dx = way[i][1];

      int ty = cy + dy, tx = cx + dx;
      if(ty < 0 || ty >= h || tx < 0 || tx >= w) continue;
      if(stage[ty][tx]) continue;

      if(depth[ty][tx] > depth[cy][cx]){
        depth[ty][tx] = depth[cy][cx];
        deq.push_front(mp(ty, tx));
      }
    }

    for(int dy = -2; dy <= 2; dy++){
      for(int dx = -2; dx <= 2; dx++){
        int ty = cy + dy, tx = cx + dx;
        if(ty < 0 || ty >= h || tx < 0 || tx >= w) continue;
        if(stage[ty][tx]) continue;

        if(depth[ty][tx] > depth[cy][cx] + 1){
          depth[ty][tx] = depth[cy][cx] + 1;
          deq.push_back(mp(ty, tx));
        }
      }
    }
  }

  if(depth[gy][gx] == infi) cout << -1 << endl;
  else cout << depth[gy][gx] << endl;
}