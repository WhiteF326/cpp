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

int h, w;
vector<vector<int>> c(16, vector<int>(16, 1));
int ans = 0;
vector<vector<int>> visited(16, vector<int>(16, 0));

constexpr int way[4][2] = {
  {-1, 0},
  {0, -1},
  {0, 1},
  {1, 0}
};

void dfs(int y, int x, int depth){
  for(int i = 0; i < 4; i++){
    int dy = y + way[i][0], dx = x + way[i][1];
    if(dy < 0 || dy >= h || dx < 0 || dx >= w) continue;
    if(visited[dy][dx] == 1 || c[dy][dx]) continue;

    if(visited[dy][dx] == -1){
      ans = max(ans, depth + 1);
      return;
    }

    visited[dy][dx] = 1;
    dfs(dy, dx, depth + 1);
    visited[dy][dx] = 0;
  }
}

int main(){
  cin >> h >> w;
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++) c[i][j] = s[j] == '#';
  }

  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      visited[i][j] = -1;
      dfs(i, j, 0);
      visited[i][j] = 0;
    }
  }

  if(ans >= 3) cout << ans << endl;
  else cout << -1 << endl;
}