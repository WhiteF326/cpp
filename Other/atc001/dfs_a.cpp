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

int h, w;
int sy, sx, gy, gx;
vector<vector<int>> stage(500, vector<int>(500, 0));
vector<vector<bool>> visited(500, vector<bool>(500, false));
vector<vector<int>> way = {
  {-1, 0},
  {1, 0},
  {0, -1},
  {0, 1}
};

void dfs(int y, int x){
  if(visited[y][x]) return;
  visited[y][x] = true;
  
  for(auto v : way){
    int dy = y + v[0], dx = x + v[1];
    if(dy < 0 || dy >= h || dx < 0 || dx >= w) continue;
    if(!stage[dy][dx]) dfs(dy, dx);
  }
}

int main(){
  cin >> h >> w;
  
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      stage[i][j] = s[j] == '#';
      if(s[j] == 's'){
        sy = i, sx = j;
      }
      if(s[j] == 'g'){
        gy = i, gx = j;
      }
    }
  }

  dfs(sy, sx);
  cout << (visited[gy][gx] ? "Yes" : "No") << endl;
}