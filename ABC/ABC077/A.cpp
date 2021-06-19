#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

ll expow(ll x, ll n) {
  ll ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

int main(){
  string c1, c2; cin >> c1 >> c2;
  if(c1[0] == c2[2] && c1[1] == c2[1] && c1[2] == c2[0]) cout << "YES" << endl;
  else cout << "NO" << endl;
}