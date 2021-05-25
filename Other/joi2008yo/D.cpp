#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int m; cin >> m;
  vector<pair<int, int>> cnsmove(m - 1);
  int tx, ty; cin >> tx >> ty;
  int cx = tx, cy = ty;
  for(int i = 0; i < m - 1; i++){
    int x, y; cin >> x >> y;
    cnsmove[i] = mp(tx - x, ty - y);
    tx = x, ty = y;
  }
  int n; cin >> n;
  map<pair<int, int>, bool> stage;
  queue<pair<int, int>> stars;
  for(int i = 0; i < n; i++){
    int x, y; cin >> x >> y;
    auto dest = mp(x, y);
    stage[dest] = true;
    stars.push(dest);
  }
  while(!stars.empty()){
    bool flg = true;
    auto start = stars.front();
    stars.pop();
    int x = start.first, y = start.second;
    for(int i = 0; i < m - 1; i++){
      x -= cnsmove[i].first, y -= cnsmove[i].second;
      auto next = mp(x, y);
      if(!stage[next]){
        flg = false;
        break;
      }
    }
    if(flg){
      cout << ((cx - start.first) * -1) << " " << ((cy - start.second) * -1) << endl;
      return 0;
    }
  }
}