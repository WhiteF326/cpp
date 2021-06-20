#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

ll taxinclude(ll x, int tax){
  return x * tax / 100;
}

int main(){
  ll t; cin >> t;
  ll n; cin >> n;

  ll res = n * (100 + t);
  if(res % t){
    cout << res / t << endl;
  }else{
    cout << res / t - 1 << endl;
  }
}