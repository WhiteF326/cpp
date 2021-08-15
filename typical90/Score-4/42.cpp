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

const ll modv = (1e+9)+7;

int main(){
  int k; cin >> k;
  if(k % 9){
    cout << 0 << endl;
    return 0;
  }
  
  // dp[i] = 桁総和 i である場合の答え
  vector<ll> dp(k + 1, 0);
  dp[0] = 1;
  for(int i = 1; i <= k; i++){
    for(int j = 1; j <= min(i, 9); j++) dp[i] = (dp[i - j] + dp[i]) % modv;
  }
  cout << dp[k] << endl;
}