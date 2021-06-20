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
  int n; cin >> n;
  vector<ll> a(n + 1, 0);
  for(int i = 1; i <= n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  ll ans = 1;
  for(int i = 1; i <= n; i++){
    ans *= (a[i] - a[i - 1] + 1);
    ans %= 1000000007;
  }
  cout << ans << endl;
}