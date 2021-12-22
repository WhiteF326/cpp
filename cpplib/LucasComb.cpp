#include <bits/stdc++.h>
using namespace std;

using ll = long long;


struct Comb {
  vector<vector<ll>> com;
  ll p;
  Comb(ll _p) : p(_p) {
    init(p);
  }

  void init(ll p) {
    com.assign(p, vector<ll>(p));
    com[0][0] = 1;
    for (int i = 1; i < p; i++) {
      com[i][0] = 1;
      for (int j = i; j > 0; j--) {
        com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % p;
      }
    }
  }

  ll C(ll n, ll k) {
    ll ret = 1;
    while(n > 0){
      int ni = n % p;
      int ki = k % p;
      ret *= com[ni][ki];
      ret %= p;
      n /= p;
      k /= p;
    }
    return ret;
  }
};