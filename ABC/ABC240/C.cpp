#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, x; cin >> n >> x;
  vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, 0));
  dp[0][0] = 1;

  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    for(int j = 0; j <= x; j++){
      if(!dp[i][j]) continue;
      if(j + a <= x) dp[i + 1][j + a] = 1;
      if(j + b <= x) dp[i + 1][j + b] = 1;
    }
  }

  cout << (dp[n][x] ? "Yes" : "No") << endl;
}
