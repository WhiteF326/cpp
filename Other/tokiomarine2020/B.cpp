#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  ll a, v; cin >> a >> v;
  ll b, w; cin >> b >> w;
  ll t; cin >> t;
  if(abs(a - b) <= (v - w) * t) cout << "YES" << endl;
  else cout << "NO" << endl;
}