#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  ll x, y; cin >> x >> y;
  if(x < y) cout << x << endl;
  else if(y == 1) cout << -1 << endl;
  else if(y % x && x % y) cout << (y + 1) * x << endl;
  else cout << -1 << endl;
}