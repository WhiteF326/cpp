#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  //
  int s; cin >> s;
  // dp[v] = 総和がvとなる数列の個数
  // 初期条件 1, -
  vector<ll> dp(s + 1, 0);
  dp[0] = 1;
  for(int i = 3; i <= s; i++){
    for(int j = 0; j <= i - 3; j++){
      dp[i] += dp[j];
      dp[i] %= 1000000007;
    }
  }

  cout << dp[s] << endl;
}