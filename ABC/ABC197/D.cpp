#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

double torad(double deg){
  return deg * 3.14159265358979 / 180;
}

int main(){
  int n; cin >> n;
  ld x0, y0, xe, ye; cin >> x0 >> y0 >> xe >> ye;
  
  // center
  ld xc = (x0 + xe) / 2.0, yc = (y0 + ye) / 2.0;
  
  // vector to x0, y0
  ld xv0 = x0 - xc, yv0 = y0 - yc;

  // turn amount
  ld a = 360.0 / n;
  a = torad(a);

  // turn to x1, v1
  ld xv1 = xv0 * cos(a) - yv0 * sin(a);
  ld yv1 = xv0 * sin(a) + yv0 * cos(a);
  
  cout << fs(12) << xv1 + xc << " " << yv1 + yc << endl;
}