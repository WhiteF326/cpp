#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll a, b, x; cin >> a >> b >> x;
  ll ans = b / x;
  ans -= (a / x);
  if(a % x == 0)ans++;
  cout << ans << endl;
}