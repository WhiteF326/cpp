#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;

int main(){
  ld l, x, y, s, d;
  cin >> l >> x >> y >> s >> d;

  // 時計周り
  ld rdist = d - s;
  if(rdist < 0) rdist += l;
  ld rtime = rdist / (x + y);
  // 反時計
  if(y - x > 0){
    ld ldist = s - d;
    if(ldist < 0) ldist += l;
    cout << fs(12) << min(rtime, ldist / (y - x)) << endl;
  }else{
    cout << fs(12) << rtime << endl;
  }
}