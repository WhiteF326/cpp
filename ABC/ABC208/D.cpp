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

const ll infl = LLONG_MAX / 2LL;

int main(){
  int n, m; cin >> n >> m;
  vector<vector<ll>> wsl(n, vector<ll>(n, infl));
  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    wsl[a - 1][b - 1] = c;
  }
  for(int i = 0; i < n; i++) wsl[i][i] = 0;

  ll ans = 0;
  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        chmin(wsl[i][j], wsl[i][k] + wsl[k][j]);
      }
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(wsl[i][j] < infl) ans += wsl[i][j];
      }
    }
    // cout << ans << endl;
  }
  cout << ans << endl;
}