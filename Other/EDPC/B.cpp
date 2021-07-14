#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, k; cin >> n >> k;
  vector<int> h(n);
  for(int i = 0; i < n; i++) cin >> h[i];

  vector<int> dp(n + k + 1, INT_MAX);
  dp[0] = 0;
  for(int i = 1; i < n; i++){
    for(int j = 1; j <= k; j++){
      if(i - j >= 0) dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
    }
  }
  cout << dp[n - 1] << endl;
}