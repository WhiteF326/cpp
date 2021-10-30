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
  ll n; cin >> n;
  vector<ld> a(n);
  aryin(a, n);

  // dp[i][j] = i 日目に j を選んだ時の最高値
  vector<vector<pair<ld, ld>>> dp(n + 1, vector<pair<ld, ld>>(2, mp(0, 0)));
  vector<vector<int>> back(n + 1, vector<int>(2, 0));
  dp[0][0] = mp(1, 0);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 2; j++){
      // 金を売る
      if(dp[i][j].first){
        if(dp[i + 1][1].second <= dp[i][j].first * a[i]){
          dp[i + 1][1].second = dp[i][j].first * a[i];
          back[i + 1][1] = 1;
        }
      }
      // 銀を売る
      if(dp[i][j].second){
        if(dp[i + 1][1].first <= dp[i][j].second / a[i]){
          dp[i + 1][1].first = dp[i][j].second / a[i];
          back[i + 1][1] = 1;
        }
      }
      // 売らない
      if(dp[i][0].first <= dp[i][j].first){
        dp[i + 1][0].first = dp[i][j].first;
        back[i + 1][0] = 0;
      }
      if(dp[i][0].second <= dp[i][j].second){
        dp[i + 1][0].second = dp[i][j].second;
        back[i + 1][0] = 0;
      }
    }
  }

  // 経路復元
  int res = dp[n][0].first > dp[n][1].first ? 0 : 1;
  stack<int> s;
  for(int i = n; i >= 1; i--){
    s.push(res);
    res = back[i][res];
  }
  while(!s.empty()){
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}