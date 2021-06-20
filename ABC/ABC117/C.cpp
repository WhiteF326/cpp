#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

ll modpow(ll x, ll n, int mod){
  ll ret = 1;
  if(mod == 0){
    while(n > 0){
      if(n & 1) ret *= x;
      x *= x;
      n >>= 1;
    }
  }else{
    while(n > 0){
      if(n & 1) ret = ret * x % mod;
      x = x * x % mod;
      n >>= 1;
    }
  }
  return ret;
}

int main(){
  int n, m; cin >> n >> m;
  n--;
  vector<ll> p(m);
  for(int i = 0; i < m; i++) cin >> p[i];
  sort(p.begin(), p.end());

  vector<ll> ps(m - 1);
  for(int i = 0; i < m - 1; i++) ps[i] = p[i + 1] - p[i];

  sort(ps.begin(), ps.end());
  ll ans = 0;
  for(int i = 0; i < m - 1 - n; i++){
    ans += ps[i];
  }
  cout << ans << endl;
}