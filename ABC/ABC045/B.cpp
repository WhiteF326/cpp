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
  string a, b, c; cin >> a >> b >> c;
  string next = "a";
  while(true){
    if(next == "a"){
      if(a.empty()){
        cout << "A" << endl;
        return 0;
      }else{
        next = a.substr(0, 1);
        a = a.substr(1);
      }
    }else if(next == "b"){
      if(b.empty()){
        cout << "B" << endl;
        return 0;
      }else{
        next = b.substr(0, 1);
        b = b.substr(1);
      }
    }else{
      if(c.empty()){
        cout << "C" << endl;
        return 0;
      }else{
        next = c.substr(0, 1);
        c = c.substr(1);
      }
    }
  }
}