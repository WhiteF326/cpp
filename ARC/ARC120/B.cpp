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


int main(){
  int h, w; cin >> h >> w;
  vector<vector<int>> stg(h, vector<int>(w, 0));

  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      switch(s[j]){
        case '.':
          break;
        case 'R':
          stg[i][j] = 1;
          break;
        case 'B':
          stg[i][j] = 2;
          break;
      }
    }
  }

  ll ans = 1;

  for(int i = 0; i < h + w - 1; i++){
    map<int, int> apr;
    for(int x = 0; x < w; x++){
      int y = i - x;
      if(y >= h || y < 0) continue;
      apr[stg[y][x]]++;
    }
    if(apr[1] && apr[2]){
      ans *= 0;
    }else if(!apr[1] && !apr[2]){
      ans *= 2;
    }
    ans %= 998244353;
  }

  cout << ans << endl;
}