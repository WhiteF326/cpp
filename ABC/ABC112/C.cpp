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
  int n; cin >> n;
  vector<vector<int>> p(n, vector<int>(3, 0));
  int lx = 101, hy = 101, rx = -1, ly = -1;
  for(int i = 0; i < n; i++){
    cin >> p[i][0] >> p[i][1] >> p[i][2];
    lx = min(lx, p[i][0]);
    hy = min(hy, p[i][1]);
    rx = max(rx, p[i][0]);
    ly = max(ly, p[i][1]);
  }

  for(int y = hy; y <= ly; y++){
    for(int x = lx; x <= rx; x++){
      int h = 0;
      for(int i = 0; i < n; i++){
        if(p[i][2]){
          h = p[i][2] + abs(x - p[i][0]) + abs(y - p[i][1]);
          break;
        }
      }
      // 検証
      bool flg = true;
      for(int i = 0; i < n; i++){
        int est = max(0, h - abs(x - p[i][0]) - abs(y - p[i][1]));
        if(est != p[i][2]){
          flg = false;
        }
      }
      if(flg){
        cout << x << " " << y << " " << h << endl;
      }
    }
  }
}