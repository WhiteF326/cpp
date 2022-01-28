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
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


#define mint modint1000000007
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, x; cin >> n >> x;
  vector<int> s(n);
  aryin(s, n);

  sort(all(s));

  // dp[i][j] = i 番目の数字を先頭に挿入して j になる
  vector<vector<mint>> dp(n + 1, vector<mint>(x + 1, 0));
  for(int i = 0; i <= x; i++) dp[0][i] = i;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= x; j++){
      dp[i + 1][j] += dp[i][j % s[i]];
      dp[i + 1][j] += dp[i][j] * i;
    }
  }
  
  cout << dp[n][x].val() << endl;
}