#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

double torad(double x){
  return x * 3.14159265358979 / 180.0;
}

int main(){
  double n; cin >> n;
  ld x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;

  // 角度
  double k = 360 / n;

  // ベクトル
  ld xv = (x1 - x0) / 2.0, yv = (y1 - y0) / 2.0;
  // 重心
  ld xd = (x1 + x0) / 2.0, yd = (y1 + y0) / 2.0;
  // ベクトル量
  ld vm = sqrt(xv * xv + yv * yv);
  // 回転行列を作用させる
  ld xt = xv * cos(torad(k)) - yv * sin(torad(k));
  ld yt = xv * sin(torad(k)) + yv * cos(torad(k));

  cout << fs(12) << xt + xd << " " << yt + yd << endl;
}