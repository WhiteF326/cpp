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
  int a; cin >> a;
  for(int i = 1; i < n; i++){
    int b; cin >> b;
    a = gcd(a, b);
  }
  cout << a << endl;
}