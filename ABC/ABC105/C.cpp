#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
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
  ll n; cin >> n;
  bool mf = (n < 0);
  n = llabs(n);
}