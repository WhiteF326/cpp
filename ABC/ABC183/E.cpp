#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

const ll modv = 1000000007;
#define mint modint1000000007

int main(){
  int h, w; cin >> h >> w;
  vector<vector<int>> stage(h, vector<int>(w, 0));
  for(int i = 0; i < h; i++){
    string s; cin >> s;
    for(int j = 0; j < w; j++){
      stage[i][j] = s[j] == '#';
    }
  }

  vector<vector<mint>> dp(h + 1, vector<mint>(w + 1, 0));
  vector<vector<mint>> x(dp), y(dp), z(dp);
  dp[1][1] = 1;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(stage[i][j]){
        x[i + 1][j + 1] = y[i + 1][j + 1] = z[i + 1][j + 1] = 0;
        continue;
      }

      dp[i + 1][j + 1] += x[i + 1][j] + y[i][j + 1] + z[i][j];

      x[i + 1][j + 1] = x[i + 1][j] + dp[i + 1][j + 1];
      y[i + 1][j + 1] = y[i][j + 1] + dp[i + 1][j + 1];
      z[i + 1][j + 1] = z[i][j] + dp[i + 1][j + 1];
    }
  }
  
  cout << dp[h][w].val() << endl;
}