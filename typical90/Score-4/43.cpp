#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
 
#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define gt(a, t) get<a>(t)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ti = tuple<int, int, int>;
using ll = long long;
using ld = long double;

int main(){
  // ulrd = 0123
  vector<vector<int>> vct = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
  int h, w; cin >> h >> w;
  int rs, cs, rt, ct; cin >> rs >> cs >> rt >> ct;
  rs--, cs--, rt--, ct--;
  vector<vector<int>> stage(h, vector<int>(w, 0));
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      stage[i][j] = (s[j] == '#');
    }
  }

  // point(r * w + c), direction
  priority_queue<ti, vector<ti>, greater<ti>> q;
  for(int i = 0; i < 4; i++) q.push({0, rs * w + cs, i});
  vector<vector<int>> depth(h, vector<int>(w, INT_MAX));
  depth[rs][cs] = 0;

  while(!q.empty()){
    auto dest = q.top();
    q.pop();
    int rc = gt(1, dest) / w, cc = gt(1, dest) % w;
    for(int i = 0; i < 4; i++){
      int rd = rc + vct[i][0], cd = cc + vct[i][1];
      if(rd < 0 || rd >= h || rc < 0 || rc >= w) continue;
      if(stage[rd][cd]) continue;

      if(i == gt(2, dest) && depth[rd][cd] >= gt(0, dest)){
        depth[rd][cd] = gt(0, dest);
        q.push({gt(0, dest), rd * w + cd, i});
      }else if(i != gt(2, dest) && depth[rd][cd] >= gt(0, dest) + 1){
        depth[rd][cd] = gt(0, dest) + 1;
        q.push({gt(0, dest) + 1, rd * w + cd, i});
      }
    }
  }
  
  cout << depth[rt][ct];
}