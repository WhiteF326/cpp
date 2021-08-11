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

int main(){
  int h, w, d; cin >> h >> w >> d;
  vector<ll> acc(h * w + 1, 0);
  map<int, pair<int, int>> p;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      int a; cin >> a;
      p[a] = mp(i, j);
    }
  }
  // d個飛ばしに累積和を取る
  for(int i = d + 1; i <= h * w; i++){
    acc[i] = acc[i - d] + abs(p[i].first - p[i - d].first) + abs(p[i].second - p[i - d].second);
  }

  int q; cin >> q;
  for(int i = 0; i < q; i++){
    int l, r; cin >> l >> r;
    cout << acc[r] - acc[l] << endl;
  }
}