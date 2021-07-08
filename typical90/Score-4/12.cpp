// DSU is difficult

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

vector<vector<int>> vct = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int main(){
  int h, w; cin >> h >> w;
  vector<vector<bool>> stage(h, vector<bool>(w, 0));
  dsu gp(4000000);
  queue<string> anslist;
  int q; cin >> q;
  for(int i = 0; i < q; i++){
    int t; cin >> t;
    if(t == 1){
      int r, c; cin >> r >> c;
      r--, c--;
      stage[r][c] = true;
      int y = r, x = c;
      for(int i = 0; i < 4; i++){
        r = y + vct[i][0], c = x + vct[i][1];
        if(r >= 0 && r < h && c >= 0 && c < w){
          if(stage[r][c]){
            gp.merge(r * w + c, y * w + x);
          }
        }
      }
    }else{
      int ra, ca, rb, cb; cin >> ra >> ca >> rb >> cb;
      ra--, ca--, rb--, cb--;
      // cout << gp.size(ra * h + ca) << " " << gp.size(rb * h + cb) << endl;
      if(gp.same(ra * w + ca, rb * w + cb) && stage[ra][ca] && stage[rb][cb]) anslist.push("Yes");
      else anslist.push("No");
    }
  }
  while(!anslist.empty()){
    cout << anslist.front() << endl;
    anslist.pop();
  }
}