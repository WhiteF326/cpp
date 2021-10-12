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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];

vector<vector<int>> way = {
  {-1, 0},
  {1, 0},
  {0, -1},
  {0, 1}
};

int main(){
  int r, c; cin >> r >> c;
  int sy, sx, gy, gx; cin >> sy >> sx >> gy >> gx;
  sy--, sx--, gy--, gx--;
  vector<vector<int>> stage(r, vector<int>(c, 0));
  for(int i = 0; i < r; i++){
    string s; cin >> s;
    for(int j = 0; j < c; j++){
      stage[i][j] = s[j] == '#';
    }
  }

  queue<int> q;
  q.push(sy * c + sx);
  vector<vector<bool>> visited(r, vector<bool>(c, false));
  visited[sy][sx] = true;
  vector<vector<int>> depth(r, vector<int>(c, INT_MAX));
  depth[sy][sx] = 0;
  while(!q.empty()){
    int dest = q.front();
    q.pop();

    for(auto v : way){
      int dy = dest / c + v[0], dx = (dest % c) + v[1];
      if(dy < 0 || dy >= r || dx < 0 || dx >= c) continue;
      if(!visited[dy][dx] && !stage[dy][dx]){
        q.push(dy * c + dx);
        depth[dy][dx] = depth[dest / c][dest % c] + 1;
        visited[dy][dx] = true;
      }
    }
  }

  cout << depth[gy][gx] << endl;
}