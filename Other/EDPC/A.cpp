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
  vector<int> h(n);
  for(int i = 0; i < n; i++) cin >> h[i];

  vector<int> dp(n + 5, INT_MAX);
  dp[0] = 0;
  for(int i = 1; i < n; i++){
    dp[i] = min(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
    if(i - 2 >= 0) dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
  }
  cout << dp[n - 1] << endl;
}