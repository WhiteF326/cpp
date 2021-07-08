#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

ll modv = 1000000007;

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
  string s; cin >> s;

  map<char, int> ap;
  ll ans = 1;
  ll len = 0;
  int start = 0;
  for(int i = 0; i < n; i++){
    ap[s[i]]++;
  }
  for(auto x : ap){
    ans *= (x.second + 1);
    ans %= modv;
  }
  cout << ans - 1 << endl;
}