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

int main(){
  ll n, m; cin >> n >> m;
  ll ans = gcdlcm().lcm(n, m);

  string s, t; cin >> s >> t;

  // 構築
  ll nstep = ans / n, mstep = ans / m;
  for(ll i = 0; i <= ans; i += nstep){
    if(i % mstep == 0){
      ll a = i / nstep;
      ll b = i / mstep;
      if(s[a] != t[b]){
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << ans << endl;
}