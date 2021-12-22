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


int main(){
  int h, w; cin >> h >> w;

  vector<vector<int>> stage(h, vector<int>(w, 0));
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      stage[i][j] = s[j] == '#';
    }
  }

  queue<int> q;
  q.push(0);

  vector<vector<int>> visited(h, vector<int>(w, 0));
  visited[0][0] = 1;
  vector<vector<int>> depth(h, vector<int>(w, 0));
  
  while(!q.empty()){
    int dest = q.front();
    q.pop();

    int cy = dest / w;
    int cx = dest % w;

    // 右
    if(cx + 1 < w){
      if(!visited[cy][cx + 1] && !stage[cy][cx + 1]){
        q.push(cy * w + cx + 1);
        visited[cy][cx + 1] = true;
        depth[cy][cx + 1] = depth[cy][cx] + 1;
      }
    }
    // 下
    if(cy + 1 < h){
      if(!visited[cy + 1][cx] && !stage[cy + 1][cx]){
        visited[cy + 1][cx] = true;
        depth[cy + 1][cx] = depth[cy][cx] + 1;
        q.push(cy * w + w + cx);
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < h; i++){
    ans = max(ans, *max_element(all(depth[i])));
  }

  cout << ans + 1 << endl;
}