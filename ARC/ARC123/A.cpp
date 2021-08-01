#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

ll mceild2(ll a){
  if(a % 2) return a / 2 + 1;
  else return a / 2;
}

ll llmin(ll a, ll b){
  if(a < b) return a;
  else return b;
}

int main(){
  ll a, b, c; cin >> a >> b >> c;
  ll x = 2 * b - a - c;
  ll k = 0;
  if(x < 0) k = (1 - x) / 2;
  cout << x + 3 * k << endl;
}