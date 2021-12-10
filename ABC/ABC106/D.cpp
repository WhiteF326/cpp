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


int main(){
  int n, m, q; cin >> n >> m >> q;
  vector<vector<int>> x(n + 1, vector<int>(n + 1, 0));
  for(int i = 0; i < m; i++){
    int l, r; cin >> l >> r;
    x[l][r]++;
  }

  for(int l = 1; l <= n; l++){
    for(int r = 2; r <= n; r++){
      x[l][r] += x[l][r - 1];
    }
  }

  query(q){
    int l, r; cin >> l >> r;
    int ans = 0;
    for(int i = l; i <= r; i++) ans += x[i][r];
    cout << ans << endl;
  }
}