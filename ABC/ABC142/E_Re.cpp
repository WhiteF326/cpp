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
#define chmin(a, b) a = min(a, b)


#define infl 2000000000

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  vector<pair<int, vector<int>>> v(m, pair<int, vector<int>>());
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    v[i].first = a;
    for(int j = 0; j < b; j++){
      int c; cin >> c;
      v[i].second.emplace_back(c - 1);
    }
  }

  vector<vector<int>> dp(m + 1, vector<int>((1 << n), infl));
  dp[0][0] = 0;

  for(int i = 0; i < m; i++){
    for(int j = 0; j < (1 << n); j++){
      if(dp[i][j] != infl){
        chmin(dp[i + 1][j], dp[i][j]);
        vector<int> current(n);
        int d = 0;
        for(int k = 0; k < n; k++) current[k] = ((1 << k) & j ? 1 : 0);
        for(int p : v[i].second) current[p] = 1;
        for(int k = 0; k < n; k++) d |= (1 << k) * current[k];
        chmin(dp[i + 1][d], dp[i][j] + v[i].first);
      }
    }
  }

  if(dp[m][((1 << n) - 1)] != infl){
    cout << dp[m][((1 << n) - 1)] << endl;
  }else{
    cout << -1 << endl;
  }
}