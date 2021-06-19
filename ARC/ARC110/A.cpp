#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

ll gcd(ll x,ll y){
  if(x < y) swap(x, y);
  ll r;
  while(y > 0){
    r = x % y;
    x = y;
    y = r;
  }
  return x;
}
 
ll lcm(ll x,ll y){
  return ll(x / gcd(x, y)) * y;
}

int main(){
  int n; cin >> n;
  ll ans = 1;
  for(int i = 2; i <= n; i++){
    ans = lcm(ans, i);
  }
  cout << ans + 1 << endl;
}