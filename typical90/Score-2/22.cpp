#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

ll gcd(ll x, ll y){
  while(y > 0){
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}

int main(){
  ll a, b, c; cin >> a >> b >> c;
  ll x = gcd(a, gcd(b, c));
  cout << a / x + b / x + c / x - 3 << endl;
}