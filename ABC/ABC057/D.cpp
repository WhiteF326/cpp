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


bool chmax(ll &a, ll b){
  if(a >= b){
    return false;
  }else{
    a = b;
    return true;
  }
}

int main(){
  int n, a, b; cin >> n >> a >> b;
  vector<ll> v(n); aryin(v, n);

  // dp[i][j][k] = i 番目まで、j 個選んだ / i を選んだかは k
  vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(2, 0)));
  // その場合における最大値
  vector<vector<vector<ll>>> mx(n + 1, vector<vector<ll>>(n + 1, vector<ll>(2, 0)));
  dp[0][0][1] = 1;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < 2; k++){
        if(!dp[i][j][k]) continue;
        // 選ぶ
        if(mx[i + 1][j + 1][1] < mx[i][j][k] + v[i]){
          mx[i + 1][j + 1][1] = mx[i][j][k] + v[i];
          dp[i + 1][j + 1][1] = dp[i][j][k];
        }else if(mx[i + 1][j + 1][1] == mx[i][j][k] + v[i]){
          dp[i + 1][j + 1][1] += dp[i][j][k];
        }
        // 選ばない
        if(mx[i + 1][j][0] < mx[i][j][k]){
          mx[i + 1][j][0] = mx[i][j][k];
          dp[i + 1][j][0] = dp[i][j][k];
        }else if(mx[i + 1][j][0] == mx[i][j][k]){
          dp[i + 1][j][0] += dp[i][j][k];
        }
      }
    }
  }

  map<ld, ll> vl;
  for(int k = 0; k < 2; k++){
    for(int i = a; i <= b; i++){
      vl[mx[n][i][k] / (ld)i] += dp[n][i][k];
    }
  }

  cout << fs(12) << vl.rbegin()->first << endl;
  cout << vl.rbegin()->second << endl;
}