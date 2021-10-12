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
  {0, -1},
  {0, 1},
  {1, 0},
  {-1, 0}
};


int main(){
  int h, w; cin >> h >> w;
  vector<vector<int>> stg(h, vector<int>(w, 0));

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  vector<vector<bool>> visited(h, vector<bool>(w));
  vector<vector<int>> depth(h, vector<int>(w, INT_MAX));

  auto pos = [&](int y, int x){
    return y * w + x;
  };
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      if(s[j] == '#'){
        stg[i][j] = 1;
        visited[i][j] = true;
        depth[i][j] = 0;
        q.push(mp(0, pos(i, j)));
      }
    }
  }

  

  while(!q.empty()){
    auto dest = q.top();
    q.pop();

    int dist = dest.first;
    int y = dest.second / w, x = dest.second % w;
    
    for(auto v : way){
      int dy = y + v[0], dx = x + v[1];
      if(dy < 0 || dy >= h || dx < 0 || dx >= w) continue;
      if(visited[dy][dx]) continue;

      visited[dy][dx] = true;
      depth[dy][dx] = depth[y][x] + 1;
      q.push(mp(depth[dy][dx], pos(dy, dx)));
    }
  }

  int ans = 0;
  for(int i = 0; i < h; i++){
    ans = max(ans, *max_element(all(depth[i])));
  }
  cout << ans << endl;
}