#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
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
  string n; cin >> n;
  if(n == "0"){
    cout << "0" << endl;
    return 0;
  }
  int k; cin >> k;
  for(int i = 0; i < k; i++){
    ll v = 0;
    for(int i = 0; i < n.length(); i++){
      v += stoll(n.substr(i, 1)) * modpow(8, n.length() - 1 - i, 0);
    }
    // cout << v << endl;
    n = "";
    while(v > 0){
      if(v % 9 == 8){
        n = "5" + n;
      }else{
        n = to_string(v % 9) + n;
      }
      v /= 9;
    }
  }
  cout << n << endl;
}