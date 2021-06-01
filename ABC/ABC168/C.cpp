#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

double rad(double deg){
  return (deg * 3.141592653589793 / 180.0);
}

int main(){
  double a, b; cin >> a >> b;
  double h, m; cin >> h >> m;

  // 分針の傾き
  double mt = ((360.0 - (m * 6)) + 90.0);
  double mx = b * cos(rad(mt));
  double my = b * sin(rad(mt));

  // 時針
  double ht = ((360.0 - (30.0 * h + (0.5 * (double)m))) + 90.0);
  double hx = a * cos(rad(ht));
  double hy = a * sin(rad(ht));

  // 差からピタゴラス定理
  double dx = mx - hx;
  double dy = my - hy;
  cout << fs(14) << sqrt(dx * dx + dy * dy) << endl;
}