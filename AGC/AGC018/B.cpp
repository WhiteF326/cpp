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
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m + 1, 0));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) cin >> a[i][j];
  }
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(n + 1, 0)));
  dp[0][1][0] = n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 2; j++){
      // スポーツ i を開催するか否かが j である時スポーツ k の参加者が dp[i][j][k]
      if(!i && !j) continue;
      
    }
  }
}