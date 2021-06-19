#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

ll gcd(ll x,ll y){
  if(x < y) swap(x, y);
  //xの方が常に大きい
  ll r;
  while(y>0){
    r = x % y;
    x = y;
    y = r;
  }
  return x;
}

ll lcm(ll x,ll y){
  return ll(x / gcd(x, y)) * y;
}

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  ll v = 1;
  for(int i = 0; i < n; i++){
    ll d; cin >> d;
    a[i] = d;
    v = lcm(v, d);
  }
  ll sum = 0;
  for(int i = 0; i < n; i++){
    sum += v / a[i];
  }
  cout << fs(12) << v / (ld)sum << endl;
}