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

int main(){
  int d; cin >> d;
  int g; cin >> g;
  g /= 100;
  vector<pair<int, int>> scores(11);
  for(int i = 0; i < d; i++){
    int p, c; cin >> p >> c;
    c /= 100;
    scores[i] = mp(p, c);
  }

  // dp[i][j] = 100i点問題までで100j点を満たすための問題数
  vector<vector<int>> dp(11, vector<int>(200000, INT_MAX));
  dp[0][0] = 0;
  for(int i = 1; i <= 10; i++){
    //
  }
}