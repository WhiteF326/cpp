#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;
 
ll expow(ll x, ll n){
  ll ans = 1;
  while(n > 0){
    if(n & 1) ans = ans * x;
    x = x * x;
    n >>= 1;
  }
  return ans;
}

int main(){
  ll a, b; cin >> a >> b;
  ll ans = 0;
  while(a % 4 != 0){
    ans = ans ^ a;
    a++;
  }
  a += ((b - a) / 4) * 4;
  while(a <= b){
    ans = ans ^ a;
    a++;
  }
  cout << ans << endl;
}
