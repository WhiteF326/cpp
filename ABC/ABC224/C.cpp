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
  int n; cin >> n;
  vector<pair<ld, ld>> p(n);
  for(int i = 0; i < n; i++){
    ld x, y; cin >> x >> y;
    p[i] = mp(x, y);
  }

  auto dist = [&](pair<ld, ld> a, pair<ld, ld> b){
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
  };
  auto heron = [&](ld a, ld b, ld c){
    ld s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
  };

  int ans = 0;
  for(int i = 0; i < n - 2; i++){
    for(int j = i + 1; j < n - 1; j++){
      for(int k = j + 1; k < n; k++){
        ld a = dist(p[i], p[j]);
        ld b = dist(p[j], p[k]);
        ld c = dist(p[k], p[i]);
        ld dim = heron(a, b, c);
        // cout << dim << endl;
        ans++;
        if(dim <= 0) ans--;
      }
    }
  }
  cout << ans << endl;
}