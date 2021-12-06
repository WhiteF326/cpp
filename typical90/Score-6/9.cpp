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


const ld pi = 3.141592653589793238;

int main(){
  int n; cin >> n;
  vector<pair<ld, ld>> p(n);
  for(int i = 0; i < n; i++){
    cin >> p[i].first >> p[i].second;
    p[i].first = floor(p[i].first);
  }

  int m = n - 1;

  ld mx = 0;
  for(int i = 0; i < n; i++){
    // center = p[i];
    vector<ld> xv;
    for(int j = 0; j < n; j++){
      // amp
      if(i == j) continue;
      xv.push_back(atan2(p[j].second - p[i].second, p[j].first - p[i].first));
    }

    sort(all(xv));
    
    for(int j = 0; j < m; j++){
      // p[j] から見て 180° に一番近い値を調べる
      ld expc = pi - abs(xv[j]);
      int start = lower_bound(all(xv), expc) - xv.begin();
      for(int p = start - 2; p < start + 2; p++){
        int lp = (p + m) % m;
        ld res = abs(xv[j] - xv[lp]) * 180 / pi;
        if(res >= 180) res = 360 - res;
        mx = max(mx, res);
      }
    }
  }

  cout << fs(12) << mx << endl;
}