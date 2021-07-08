#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

ll gcd(ll x,ll y){
  if(x < y) swap(x, y);
  ll r;
  while(y > 0){
    r = x % y;
    x = y;
    y = r;
  }
  return x;
}

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  vector<ll> to_r(n, a[0]), to_l(n, a[n - 1]);
  for(int i = 1; i < n; i++){
    to_r[i] = gcd(to_r[i - 1], a[i]);
    to_l[n - i - 1] = gcd(to_l[n - i], a[n - i - 1]);
  }
  // for(int i = 0; i < n; i++){
  //   cout << to_r[i] << " " << to_l[i] << endl;
  // }
  ll ans = max(to_l[1], to_r[n - 2]);
  for(int i = 1; i < n - 1; i++){
    ans = max(ans, gcd(to_r[i - 1], to_l[i + 1]));
  }
  cout << ans << endl;
}