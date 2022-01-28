#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
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
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


vector<vector<int>> way = {
  {-1, 0},
  {0, -1},
  {0, 1},
  {1, 0}
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int h, w; cin >> h >> w;
  int fl = 0;
  vector<vector<bool>> stage(h, vector<bool>(w, false));
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      stage[i][j] = (s.substr(j, 1) == ".");
      fl += stage[i][j];
    }
  }

  queue<int> q;
  q.push(0);
  vector<bool> visited(h * w, false);
  visited[0] = true;
  vector<int> dist(h * w, 0);
  while(!q.empty()){
    int dest = q.front();
    q.pop();

    int cy = dest / w, cx = dest % w;
    for(int i = 0; i < 4; i++){
      int dy = cy + way[i][0], dx = cx + way[i][1];
      if(dy < 0 || dy >= h || dx < 0 || dx >= w) continue;
      if(!stage[dy][dx]) continue;
      if(visited[dy * w + dx]) continue;

      q.push(dy * w + dx);
      visited[dy * w + dx] = true;
      dist[dy * w + dx] = dist[dest] + 1;
    }
  }

  if(visited[h * w - 1]){
    // たどり着ける
    cout << fl - dist[h * w - 1] - 1 << endl;
  }else{
    cout << -1 << endl;
  }
}