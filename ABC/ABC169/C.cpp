#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  ll a; ll b, c;
  scanf("%lld %lld.%lld", &a, &b, &c);
  b *= 100;
  ll ans = a * (b + c) / 100;
  cout << fs(0) << ans << endl;
}