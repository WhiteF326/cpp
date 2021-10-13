#include <utility>
using namespace std;
using ll = long long;

ll modinv(ll x, ll modv){
  ll b = modv, u = 1, v = 0;
  while(b){
    ll t = x / b;
    x -= t * b;
    swap(x, b);
    u -= t *v;
    swap(u, v);
  }
  u %= modv;
  if(u < 0) u += modv;
  return u;
}