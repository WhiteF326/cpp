#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n, k; cin >> n >> k;

  vector<int> order(n, -1);
  for(int i = 0; i < k; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    order[a] = b;
  }

  // dp[i][j] = i日目にソースjを選ぶ通り数

  vector<vector<ll>> dp(n + 1, vector<ll>(3, 0));
  dp[0][0] = 1, dp[0][1] = 1, dp[0][2] = 1;

  for(int i = 1; i <= n; i++){
    if(order[i] >= 0){
      // 指定済み
    }else{
      
    }
  }
}