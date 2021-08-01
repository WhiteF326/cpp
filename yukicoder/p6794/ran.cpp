#include <bits/stdc++.h>
#include <random>
using namespace std;

using ll = long long;

ll lim = 1e+18;
mt19937 mt;
random_device rnd;

int r(){
  return (rand() % 32768) * 32768 + (rand() % 32768);
}
ll ran(){
  return ((ll)r() * (ll)r()) % lim + r();
}

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
  mt.seed(rnd());
  for(int i = 0; i < 10; i++){
    ofstream ofs("testcases/06_esp_" + to_string(i) + ".txt");
    while(true){
      ll a = ran() % 20, b = ran() % 20;
      a++, b++;
      if(modpow(a, b, 0) != modpow(a, b, 0) % (ll)(1e+18)) continue;
      ofs << modpow(a, b, 0) << endl;
      break;
    }
  }
}