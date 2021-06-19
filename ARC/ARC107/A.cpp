#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

ll modssum(ll d){
  ll x = (ll)d;
  ll y = x * (x + 1) / 2;
  return (y % 998244353);
}

int main(){
  ll a, b, c; cin >> a >> b >> c;
  cout << (((modssum(a) * modssum(b)) % 998244353LL) * modssum(c)) % 998244353LL << endl;
}