#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int h, w; cin >> h >> w;
  vector<vector<bool>> stage(h, vector<bool>(w, true));
  int sx, sy, gx, gy;
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      string c = s.substr(j, 1);
      if(c == "."){
        stage[i][j] = true;
      }else if(c == "s"){
        stage[i][j] = true;
        sx = j, sy = i;
      }else if(c == "g"){
        stage[i][j] = true;
        gx = j, gy = i;
      }
    }
  }
// mada totyuu
}