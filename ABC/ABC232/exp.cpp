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
  int h = 4, w = 5;
  vector<vector<int>> cur(h, vector<int>(w, 0));
  cur[2][2] = 1;

  for(int i = 0; i < 5; i++){
    vector<vector<int>> ncur(h, vector<int>(w, 0));
    for(int y = 0; y < h; y++){
      for(int x = 0; x < w; x++){
        if(!cur[y][x]) continue;
        for(int j = 0; j < h; j++){
          if(j == y) continue;
          ncur[j][x] += cur[y][x];
        }
        for(int j = 0; j < w; j++){
          if(j == x) continue;
          ncur[y][j] += cur[y][x];
        }
      }
    }

    cur = ncur;

    for(int y = 0; y < h; y++){
      for(int x = 0; x < w; x++){
        cout << setw(5) << cur[y][x];
      }
      cout << endl;
    }
  }
}