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
  int a, b, c; cin >> a >> b >> c;
  vector<vector<vector<double>>> dp(101, vector<vector<double>>(101, vector<double>(101, 0)));
  for(int i = 99; i >= a; i--){
    for(int j = 99; j >= b; j--){
      for(int k = 99; k >= c; k--){
        dp[i][j][k] += (double)i / (i + j + k) * (dp[i + 1][j][k] + 1);
        dp[i][j][k] += (double)j / (i + j + k) * (dp[i][j + 1][k] + 1);
        dp[i][j][k] += (double)k / (i + j + k) * (dp[i][j][k + 1] + 1);
      }
    }
  }

  cout << fs(10) << dp[a][b][c] << endl;
}