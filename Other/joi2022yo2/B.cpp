#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


vector<vector<int>> way = {
  {-1, 0},
  {0, -1},
  {0, 1},
  {1, 0}
};
int main(){
  int h, w; cin >> h >> w;
  vector<vector<int>> stage(h, vector<int>(w, 0));
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      if(s[j] == '#') stage[i][j] = 1;
    }
  }

  queue<int> q;
  q.push(0);
  vector<vector<int>> visited(h, vector<int>(w, 0));
  visited[0][0] = 1;
  vector<vector<int>> depth(h, vector<int>(w, INT_MAX));
  depth[0][0] = 0;

  while(!q.empty()){
    int dest = q.front();
    q.pop();

    int cy = dest / w;
    int cx = dest % w;

    for(int i = 0; i < 4; i++){
      int dy = cy + way[i][0];
      int dx = cx + way[i][1];

      if(dy < 0 || dy >= h || dx < 0 || dx >= w) continue;
      if(stage[cy][cx] == stage[dy][dx]) continue;
      
      if(visited[dy][dx]) continue;
      visited[dy][dx] = true;
      depth[dy][dx] = depth[cy][cx] + 1;
      q.push(dy * w + dx);
    }
  }

  if(visited[h - 1][w - 1]){
    cout << depth[h - 1][w - 1] << endl;
  }else{
    cout << -1 << endl;
  }
}