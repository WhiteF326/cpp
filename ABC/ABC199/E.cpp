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
#define chmin(a, b) a = min(a, b)
#define vc vector


int main(){
  int n, m; cin >> n >> m;

  vc<vc<ll>> dp(n + 1, vc<ll>(1 << n, 0));
  dp[0][0] = 1;

  vc<vc<pair<int, int>>> jd(n + 1);
  for(int i = 0; i < m; i++){
    int x, y, z; cin >> x >> y >> z;
    jd[x].push_back(mp(y, z));
  }

  // cout << 1 << endl;

  for(int j = 0; j < (1 << n); j++){
    int i = 0;
    for(int x = 0; x < n; x++){
      if(j & (1 << x)) i++;
    }
    if(!dp[i][j]) continue;
    for(int k = 0; k < n; k++){
      if(j & (1 << k)) continue;
      // まだ選ばれていない数字なら選ぼうとする
      int st = j | (1 << k);
      // 条件を満たすか
      bool flg = true;
      for(auto p : jd[i + 1]){
        int rsum = 0;
        for(int v = 0; v < p.first; v++){
          if(st & (1 << v)) rsum++;
        }
        if(rsum > p.second) flg = false;
      }

      if(flg){
        // 満たすなら遷移する
        dp[i + 1][st] += dp[i][j];
      }
    }
  }

  cout << dp[n][(1 << n) - 1] << endl;
}