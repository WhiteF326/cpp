#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int h, w; cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w, 0));
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++) cin >> a[i][j];
  }
  vector<int> h_ac(h, 0), w_ac(w, 0);
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      h_ac[i] += a[i][j];
      w_ac[j] += a[i][j];
    }
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cout << h_ac[i] + w_ac[j] - a[i][j];
      if(j != w - 1) cout << " ";
    }
    cout << endl;
  }
}