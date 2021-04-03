#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a, b, c, x, y; cin >> a >> b >> c >> x >> y;
  long long ans = 0; long long dif = max(x, y) - min(x, y);
  //a+b ? c*2
  if(a + b > c * 2){ans += (int)min(x, y) * c * 2;
  }else{ans += (long long)min(x, y) * (a + b);}
  //残りを比較
  if(x < y && b < c * 2){ans += dif * b;}
  else if(x > y && a < c * 2){ans += dif * a;}
  else{ans += dif * c * 2;}
  cout << ans << endl;
}