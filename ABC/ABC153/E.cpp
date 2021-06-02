#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int h, n; cin >> h >> n;
  vector<pair<int, int>> magics(n);
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    magics[i] = mp(a, b);
  }
  // dp[i] = 体力をi以上減らすときの最適解における魔力消費量
  vector<int> dp(h + 1, INT_MAX);
  dp[0] = 0;
  for(int i = 1; i <= h; i++){
    for(int j = 0; j < n; j++){
      dp[i] = min(dp[i], dp[max(0, i - magics[j].first)] + magics[j].second);
    }
  }
  cout << dp[h] << endl;
}