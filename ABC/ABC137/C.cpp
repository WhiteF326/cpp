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
  map<string, ll> a;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    sort(s.begin(), s.end());
    a[s]++;
  }
  ll ans = 0;
  for(auto itr = a.begin(); itr != a.end(); itr++){
    ans += itr->second * (itr->second - 1) / 2;
  }
  cout << ans << endl;
}