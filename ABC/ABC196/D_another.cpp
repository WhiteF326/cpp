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
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int h, w; cin >> h >> w;
  int a, b; cin >> a >> b;
  int s = h * w;

  vector<vector<vector<int>>> dp(a + 1, vector<vector<int>>(b + 1, vector<int>(1 << s, 0)));
  dp[a][b][0] = 1;
  for(int k = 0; k < (1 << s); k++){
    for(int i = 0; i <= a; i++){
      for(int j = 0; j <= b; j++){
        int d = 0;
        while(k & (1 << d)) d++;
        if(d == s) continue;
        if(i){
          // 縦
          if(d / w < h - 1){
            dp[i - 1][j][k | (1 << d) | (1 << (d + w))] += dp[i][j][k];
          }
          // 横
          if(d % w < w - 1){
            dp[i - 1][j][k | (1 << d) | (1 << (d + 1))] += dp[i][j][k];
          }
        }
        if(j){
          // 1x1
          dp[i][j - 1][k | (1 << d)] += dp[i][j][k];
        }
      }
    }
  }

  cout << dp[0][0][(1 << s) - 1] << endl;
}