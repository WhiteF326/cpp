#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
  usage : fastComb(s, m, c)
  s = max value you want to use
  m = mod value (should be prime number)
  c = if you want to check m is prime, true -> Ο(sqrt(m) + log m)
      if no, false -> Ο(log m)
  
  method C(int n, int r) returns nCr mod p
*/

struct fastComb{
  vector<ll> f;
  ll modv;
  int size;

  fastComb(int size, ll modv, bool checkmodv){
    if(checkmodv){
      bool ans = true;
      if(modv < 2) ans = false;
      else if (modv == 2) ans = true;
      else{
        for(int i = 2; i <= (int)sqrt(modv); i++){
          if(modv % i == 0){
              ans = false;
          }
        }
      }
      assert(ans);
    }

    f.resize(size + 1);
    this->modv = modv;
    this->size = size;
    f[0] = 1;
    for(int i = 1; i < this->size + 1; i++) f[i] = (f[i - 1] * i) % this->modv;
  }

  ll inv(ll x){
    ll res = 1, k = modv - 2, y = x;
    while(k){
      if(k & 1) res = (res * y) % modv;
      y = y * y % modv;
      k /= 2;
    }
    return res;
  }

  ll C(int n, int r){
    assert(r <= n);
    assert(n <= this->size);
    assert(r <= this->size);

    ll a = f[n];
    ll b = f[n - r];
    ll c = f[r];
  
    ll bc = (b * c) % modv;
  
    return (a * inv(bc)) % modv;
  }
};