#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  vector<pair<int, int>> vc = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
  int h, w; cin >> h >> w;
  vector<vector<bool>> stage(h, vector<bool>(w, false));
  int wallcnt = h * w;
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      if(s.substr(j, 1) == "."){
        stage[i][j] = true;
        wallcnt--;
      }
    }
  }
  int x = 0, y = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(y, x));
  vector<vector<int>> pathlen(h, vector<int>(w, 0));
  pathlen[0][0] = 1;
  vector<vector<bool>> visited(h, vector<bool>(w, false));
  visited[0][0] = true;
  while(!q.empty()){
    auto dest = q.front();
    q.pop();
    y = dest.first, x = dest.second;
    for(int i = 0; i < 4; i++){
      int ty = y + vc[i].first, tx = x + vc[i].second;
      if(ty >= 0 && ty < h && tx >= 0 && ty < w){
        if(stage[ty][tx] && !visited[ty][tx]){
          pathlen[ty][tx] = pathlen[y][x] + 1;
          q.push(make_pair(ty, tx));
          visited[ty][tx] = true;
        }
      }
    }
  }
  if(!visited[h - 1][w - 1]){
    cout << -1 << endl;
  }else{
    cout << w * h - pathlen[h - 1][w - 1] - wallcnt<< endl;
  }
}