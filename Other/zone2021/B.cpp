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
  int n, d, h; cin >> n >> d >> h;
  ld ans = 0;
  for(int i = 0; i < n; i++){
    int x, y; cin >> x >> y;
    int dx = d - x, dy = h - y;
    ld res = max(0.0L, y - (dy / (ld)dx) * x);

    ans = max(ans, res);
  }

  cout << fs(12) << ans << endl;
}