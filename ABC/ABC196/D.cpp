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

int h, w, a, b;
vector<vector<int>> stage(16, vector<int>(16, 0));

int dfs(int x, int y, int la, int lb){
  
  if(la < 0 || lb < 0) return 0;
  if(x == w) x = 0, y++;
  if(y == h) return 1;

  if(stage[y][x]) return dfs(x + 1, y, la, lb);

  int res = 0;

  stage[y][x] = 1;

  // 1x1
  res += dfs(x + 1, y, la, lb - 1);
  // horizontal
  if(x < w - 1 && !stage[y][x + 1]){
    stage[y][x + 1] = 1;
    res += dfs(x + 1, y, la - 1, lb);
    stage[y][x + 1] = 0;
  }
  // vertical
  if(y < h - 1 && !stage[y + 1][x]){
    stage[y + 1][x] = 1;
    res += dfs(x + 1, y, la - 1, lb);
    stage[y + 1][x] = 0;
  }

  stage[y][x] = 0;

  return res;
}

int main(){
  cin >> h >> w >> a >> b;
  cout << dfs(0, 0, a, b) << endl;
}