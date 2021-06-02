#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  ll n, x; cin >> n >> x;
  x *= 100;
  for(int i = 0; i < n; i++){
    ll v, p; cin >> v >> p;
    ll alc = v * p;
    x -= alc;
    if(x < 0){
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}