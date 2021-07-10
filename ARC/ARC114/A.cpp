#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
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

constexpr int primes[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main(){
  int n; cin >> n;
  vector<ll> x(n);
  for(int i = 0; i < n; i++) cin >> x[i];

  ll ans = 1;
  for(int i : primes) ans *= i;

  for(int i = 0; i < (1 << 15); i++){
    ll res = 1;
    for(int j = 0; j < 15; j++){
      if(i & (1 << j)) res *= primes[j];
    }
    bool flg = true;
    for(int j = 0; j < n; j++){
      if(gcdlcm().gcd(res, x[j]) == 1){
        flg = false;
        break;
      }
    }
    if(flg){
      ans = min(ans, res);
    }
  }
  cout << ans << endl;
}