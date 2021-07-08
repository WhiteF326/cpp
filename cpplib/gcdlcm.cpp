#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

struct gcdlcm{
  ll gcd(ll x, ll y){
    while(y > 0){
      ll r = x % y;
      x = y;
      y = r;
    }
    return x;
  }

  ll lcm(ll x, ll y){
    return x / gcd(x, y) * y;
  }
};
