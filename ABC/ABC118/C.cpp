#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

ll modv = 1000000007;

ll modpow(ll x, ll n){
  ll ans = 1;
  while(n > 0){
    if(n & 1) ans = ans * x % modv;
    x = x * x % modv;
    n >>= 1;
  }
  return ans;
}

int main(){
  
}