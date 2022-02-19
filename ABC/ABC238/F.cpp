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


#define mint modint998244353
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, k; cin >> n >> k;
  /**
   * 出場させる K 人を選ぶとすると、
   * Px < Py または Qx < Qy であるような、代表である y が存在しなければならない。
   * P を降順に並べると、Q だけ考えればよくなり、
   * dp[i][j][k] = P の降順に i 人目を見ていて、j 人出場させると決めた時の、出場してない人の max Q
   * とすると、k > Qi である場合はその人を出場させられない。
   * そうでなければ、どちらでもよい
  */
  vector<pair<int, int>> sc(n);
  for(int i = 0; i < n; i++){
    cin >> sc[i].first;
  }
  for(int i = 0; i < n; i++){
    cin >> sc[i].second;
  }
  sort(all(sc));

  vector<vector<vector<mint>>> dp(n + 1, vector<vector<mint>>(n + 1, vector<mint>(n + 1, 0)));
  dp[0][0][n] = 1;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k <= n; k++){
        if(!dp[i][j][k].val()) continue;
        // 出場させる場合
        if(k >= sc[i].second){
          dp[i + 1][j + 1][k] += dp[i][j][k];
        }
        // 出場させない場合
        dp[i + 1][j][min(k, sc[i].second)] += dp[i][j][k];
      }
    }
  }

  mint ans = 0;
  for(int i = 0; i <= n; i++){
    ans += dp[n][k][i];
  }

  cout << ans.val() << endl;
}
