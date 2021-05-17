/*
未証明の
Greedyは
だめですか
*/

#include <bits/stdc++.h>
using namespace std;
 
#define fs(n) fixed << setprecision(n)
using ll = long long;

int main(){
  // 出来るのは右か下を選ぶことだけ
  int h, w; cin >> h >> w;
  int x = 0, y = 0;
  vector<string> stage(h, "");
  for(int i = 0; i < h; i++) cin >> stage[i];

  vector<int> scores(2, 0);
  int time = 0;

  while(true){
    // cout << x << " " << y << " " << time << endl;
    if(time == (h - 1) * (w - 1)) break;
    bool moved = false;
    int direction = 0;
    if(x < w - 1){
      // 右に進める
      x++;
      int tmp = 0, dir = 0;
      if(y + 1 < h){
        dir++;
        if(stage[y + 1][x] == '-') tmp++;
      }
      if(x + 1 < w){
        dir++;
        if(stage[y][x + 1] == '-') tmp++;
      }
      if(tmp == dir){
        moved = !moved;
        direction = 1;
      }
      x--;
    }
    if(y < h - 1){
      // 下に進める
      y++;
      int tmp = 0, dir = 0;
      if(y + 1 < h){
        dir++;
        if(stage[y + 1][x] == '-') tmp++;
      }
      if(x + 1 < w){
        dir++;
        if(stage[y][x + 1] == '-') tmp++;
      }
      if(tmp == dir){
        moved = !moved;
        direction = 2;
      }
      y--;
    }
    if(moved){
      if(direction == 1){
        x++;
      }else{
        y++;
      }
    }else{
      if(x == w - 1){
        y++;
      }else if(y == h - 1){
        x++;
      }else if(y + 1 < h){
        if(stage[y + 1][x] == '+'){
          y++;
        }else{
          x++;
        }
      }else{
        x++;
      }
    }
    scores[time % 2] += (stage[y][x] == '+' ? 1 : -1);
    time++;
  }
  if(scores[0] > scores[1]) cout << "Takahashi" << endl;
  else if(scores[0] < scores[1]) cout << "Aoki" << endl;
  else cout << "Draw" << endl;
}