#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
  ll ans = 0; ll dif = max(x, y) - min(x, y);
  //a+b ? c*2
  if(a + b > c * 2) ans += min(x, y) * c * 2;
  else ans += min(x, y) * (a + b);
  //残りを比較
  if(x < y && b < c * 2) ans += dif * b;
  else if(x > y && a < c * 2) ans += dif * a;
  else ans += dif * c * 2; 
  cout << ans << endl;
}