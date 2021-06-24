#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

double torad(double deg){
  return deg * 3.141592653589793238462 / 180;
}

double todeg(double rad){
  return rad * 180 / 3.141592653589793238462;
}

int main(){
  ld t; cin >> t;
  ld l, x, y; cin >> l >> x >> y;
  l = l / 2.0;
  int q; cin >> q;
  for(int i = 0; i < q; i++){
    ld e; cin >> e;
    e = 360.0 * e / t;
    ld ty = l * -sin(torad(e)), tz = l - l * cos(torad(e));
    ld a = sqrt(x * x + (ty - y) * (ty - y));
    // cout << ty << " " << tz << " " << a << endl;
    cout << fs(12) << todeg(atan2(tz, a)) << endl;
  }
}