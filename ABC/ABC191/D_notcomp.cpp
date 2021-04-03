#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long double x, y, r; cin >> x >> y >> r;
  long double myr[2] = {ceil(y - r), floor(y + r)};
  
  long ans = 0;
  for(int h = myr[0]; h <= myr[1]; h++){
    long double mxr[2] = {
      ceil(x - (sqrt(pow(r, 2) - pow((y - h), 2)))),
      floor(x + (sqrt(pow(r, 2) - pow((y - h), 2))))
    };
    ans += mxr[1] - mxr[0] + 1;
  }
  cout << ans << endl;
}