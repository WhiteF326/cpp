#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int h, w;
int rs, cs, rt, ct;
vector<vector<bool>> stage(1000, vector<bool>(1000, true));
vector<vector<bool>> visited(1000, vector<bool>(1000, false));
int ans = INT_MAX;
vector<vector<int>> vct = {
  {-1, 0},
  {0, -1},
  {0, 1},
  {1, 0}
};      // y, x
vector<string> ways = {"U", "L", "R", "D"};
stack<string> way;
int res = 0;

void dfs(int y, int x){
  visited[y][x] = true;
  if(y == rt && x == ct){
    ans = min(res, ans);
    visited[y][x] = false;
    return;
  }
  for(int i = 0; i < 4; i++){
    int vy = y + vct[i][0], vx = x + vct[i][1];
    if(vy < 0 || vy >= h || vx < 0 || vx >= w) continue;
    if(!stage[vy][vx]) continue;
    if(visited[vy][vx]) continue;
    // move
    if(way.empty()){
      way.push(ways[i]);
      dfs(vy, vx);
      way.pop();
    }else{
      if(way.top() != ways[i]){
        res++;
      }
      way.push(ways[i]);
      dfs(vy, vx);
      way.pop();
      if(way.top() != ways[i]){
        res--;
      }
    }
  }
  visited[y][x] = false;
}

int main(){
  cin >> h >> w;
  cin >> rs >> cs >> rt >> ct;
  rs--, cs--, rt--, ct--;
  
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      if(s[j] == '#') stage[i][j] = false;
    }
  }

  dfs(rs, cs);
  cout << ans << endl;
}