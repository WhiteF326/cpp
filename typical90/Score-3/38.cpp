#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
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
  ll a, b; cin >> a >> b;
  if(a < b) swap(a, b);
  // lcm(a, b) = a * b / gcd(a, b)
  ll g = b / gcd(a, b);
  // gcdは必ずaまたはbを割れる
  if(g > 1000000000000000000 / a) cout << "Large" << endl;
  else cout << g * a << endl;
}