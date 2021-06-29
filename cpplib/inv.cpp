#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
  usage : inv(m)
  m = prime
  
  method modinv(x) returns x^-1 mod m -> Ο(log m)
    this implementation is by Fermat's little theorem
*/

struct inv{
  ll modv;

  inv(ll modv){
    this->modv = modv;
  }

  ll modinv(ll x){
    ll res = 1, k = this->modv - 2, y = x;
    while(k){
      if(k & 1) res = (res * y) % modv;
      y = y * y % modv;
      k /= 2;
    }
    return res;
  }
};