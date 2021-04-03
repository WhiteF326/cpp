#include <bits/stdc++.h>
using namespace std;

int main(){
  double sx, sy, gx, gy; cin >> sx >> sy >> gx >> gy;
  double dx = (double)gx - sx, dy = gy + sy;
  double ans = sx + dx * sy / (double)dy;
  cout << fixed << setprecision(10) << ans << endl;
}