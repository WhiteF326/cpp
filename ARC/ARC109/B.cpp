#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  ll n; cin >> n;
  ll l = -1, r = 2000000000;
  while(r - 1 > l){
    ll m = l + (r - l) / 2;
    if(m * (m + 1) <= 2 * n + 2){
      l = m;
    }else{
      r = m;
    }
  }
  cout << n + 1 - l << endl;
}