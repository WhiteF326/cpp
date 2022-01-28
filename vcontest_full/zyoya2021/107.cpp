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


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int h, w; cin >> h >> w;
  int n; cin >> n;
  vector<int> a(n);
  aryin(a, n);

  vector<vector<int>> ans(h, vector<int>(w));
  int xv = 1, c = 0, x = 0, y = 0;
  for(int i = 0; i < h * w; i++){
    ans[x][y] = c + 1;
    a[c]--;
    if(a[c] == 0) c++;
    x += xv;
    if(x >= h){
      x--;
      xv = -1;
      y++;
    }
    if(x < 0){
      x++;
      xv = 1;
      y++;
    }
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}