#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  const vector<vector<int>> vct = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
  int h, w; cin >> h >> w;
  int floorcnt = 0;
  vector<vector<bool>> stage(h, vector<bool>(w, false));
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      stage[i][j] = (s.substr(j, 1) == ".");
      floorcnt += stage[i][j];
    }
  }
  queue<pair<int, int>> q;
  auto t = mp(0, 0); q.push(t);
  vector<vector<bool>> visited(h, vector<bool>(w, false));
  visited[0][0] = true;
  vector<vector<int>> dist(h, vector<int>(w, 0));
  while(!q.empty()){
    auto dest = q.front();
    q.pop();
    for(int i = 0; i < 4; i++){
      int y = dest.first + vct[i][0], x = dest.second + vct[i][1];
      if(y >= 0 && y < h && x >= 0 && x < w){
        // 検査
        if(stage[y][x] && !visited[y][x]){
          auto nxt = mp(y, x);
          q.push(nxt);
          visited[y][x] = true;
          dist[y][x] = dist[dest.first][dest.second] + 1;
        }
      }
    }
  }
  if(visited[h - 1][w - 1]){
    // たどり着ける
    cout << floorcnt - dist[h - 1][w - 1] - 1 << endl;
  }else{
    cout << -1 << endl;
  }
}