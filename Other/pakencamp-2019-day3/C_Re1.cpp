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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  vector<vector<ll>> a(n, vector<ll>(m, 0));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  ll ans = 0;

  for(int i = 0; i < m - 1; i++){
    for(int j = i + 1; j < m; j++){
      if(i == j) continue;

      ll res = 0;
      for(int k = 0; k < n; k++){
        res += max(a[k][i], a[k][j]);
      }
      ans = max(ans, res);
    }
  }

  cout << ans << endl;
}