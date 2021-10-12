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

vector<vector<int>> way = {
  {-1, 0},
  {0, -1},
  {0, 1},
  {1, 0}
};

int main(){
  int h, w; cin >> h >> w;
  vector<vector<int>> stage(h, vector<int>(w, 0));

  auto pos = [&](int y, int x){
    return y * w + x;
  };
  auto pr = [&](int ps){
    return mp(ps / w, ps % w);
  };

  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      if(s[j] == '#') stage[i][j] = 1;
    }
  }

  ll ans = 0;

  vector<vector<ll>> parts;
  vector<vector<bool>> visited(h, vector<bool>(w, 0));
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(visited[i][j]) continue;

      queue<int> q;
      q.push(pos(i, j));
      visited[i][j] = true;
      vector<ll> ct = {0, 0};
      ct[stage[i][j]] = 1;

      while(!q.empty()){
        int dest = q.front();
        q.pop();
        int y = pr(dest).first, x = pr(dest).second;

        for(auto v : way){
          int dy = y + v[0], dx = x + v[1];
          if(dy < 0 || dy >= h || dx < 0 || dx >= w) continue;
          if(stage[y][x] == stage[dy][dx]) continue;
          if(visited[dy][dx]) continue;

          visited[dy][dx] = true;
          ct[stage[dy][dx]]++;
          q.push(pos(dy, dx));
        }
      }

      parts.push_back(ct);
    }
  }

  for(auto p : parts){
    ans += p[0] * p[1];
  }
  cout << ans << endl;
}