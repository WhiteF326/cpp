#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int h, w; cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w, 0)), b(h, vector<int>(w, 0));
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> a[i][j];
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> b[i][j];

  ll ans = 0;
  for(int i = 0; i < h - 1; i++){
    for(int j = 0; j < w - 1; j++){
      int diff = b[i][j] - a[i][j];
      a[i][j] += diff, a[i][j + 1] += diff, a[i + 1][j] += diff, a[i + 1][j + 1] += diff;
      ans += (ll)abs(diff);
    }
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(a[i][j] != b[i][j]){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl << ans << endl;
}