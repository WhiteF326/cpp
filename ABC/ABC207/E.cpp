#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  // dp[i][j][k] = i番目まででj項目の後を切り分けるかどうかについてk(T/F)の時、条件を満たすものの個数と今の(総和と分割数)
  vector<vector<vector<pair<ll, pair<ll, ll>>>>> dp(n + 1, vector<vector<pair<ll, pair<ll, ll>>>>(n + 1, vector<pair<ll, pair<ll, ll>>>(2, make_pair(0, make_pair(0, 0)))));
  dp[1][1][0] = make_pair(1, make_pair(a[0], 0)), dp[1][1][1] = make_pair(1, make_pair(a[0], 1));
  for(int i = 1; i < n; i++){
    for(int j = 1; j < n; j++){
      if(dp[i][j][0].first){
        // まだ切り分けない
        dp[i + 1][j][0].first += dp[i][j][0].first;
        dp[i + 1][j][0].second.first = dp[i][j][0].second.first + a[i + 1];
        // ここで切り分ける
        if((dp[i][j][0].second.first + a[i + 1]) % (dp[i][j][0].second.second + 1) == 0){
          dp[i + 1][j][1].first += dp[i][j][0].first;
          dp[i + 1][j][1].second.first = dp[i][j][0].second.first + a[i + 1];
          dp[i + 1][j][1].second.second = dp[i][j][0].second.second + 1;
        }
      }
    }
  }
}