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

template <typename T>
void chmin(T& a, T b){
  a = min(a, b);
}
#define INF 1000000000000
int main(){
  int n, ma, mb; cin >> n >> ma >> mb;

  vector<int> a(n), b(n), c(n);
  for(int i = 0; i < n; i++){
    cin >> a[i] >> b[i] >> c[i];
  }

  // i 番目までの薬品で A = j, B = k
  vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(401, vector<ll>(401, INF)));
  dp[0][0][0] = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j <= 400; j++){
      for(int k = 0; k <= 400; k++){
        if(dp[i][j][k] == INF) continue;
        chmin(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
        chmin(dp[i + 1][j][k], dp[i][j][k]);
      }
    }
  }

  int m = 1;
  ll ans = INF;
  while(ma * m <= 400 && mb * m <= 400){
    chmin(ans, dp[n][ma * m][mb * m]);
    m++;
  }

  if(ans == INF){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
}