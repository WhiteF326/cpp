#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w; cin >> h >> w;
  vector<vector<bool>> stage(h, vector<bool>(w, false));
  queue<pair<int, int>> floorList;

  const vector<vector<int>> vq = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      if(s.substr(j, 1) == "."){
        stage[i][j] = true;
        floorList.push(make_pair(i, j));
      }
    }
  }

  int ans = 0;
  
  while(!floorList.empty()){
    auto floorPoint = floorList.front();
    floorList.pop();
    queue<pair<int, int>> q;
    q.push(floorPoint);
    vector<vector<int>> t_stage(h, vector<int>(w, 0));
    t_stage[floorPoint.first][floorPoint.second] = 1;
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    visited[floorPoint.first][floorPoint.second] = true;
    while(!q.empty()){
      auto dest = q.front();
      q.pop();
      int y = dest.first, x = dest.second;
      if(stage[y][x]){
        // 床
        for(int i = 0; i < 4; i++){
          int ty = y + vq[i][0], tx = x + vq[i][1];
          if(ty >= 0 && ty < h && tx >= 0 && tx < w){
            if(!visited[ty][tx] && stage[ty][tx]){
              t_stage[ty][tx] = t_stage[y][x] + 1;
              q.push(make_pair(ty, tx));
              visited[ty][tx] = true;
            }
          }
        }
      }
    }
    for(int i = 0; i < h; i++){
      ans = max(ans, *max_element(t_stage[i].begin(), t_stage[i].end()));
    }
  }

  cout << ans - 1 << endl;
}