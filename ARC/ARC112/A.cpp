#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int t; cin >> t;
  vector<ll> alist(t);
  for(int i = 0; i < t; i++){
    ll l, r; cin >> l >> r;
    if(2 * l <= r) alist[i] = (r - 2 * l + 1) * (r - 2 * l + 2) / 2;
  }
  for(int i = 0; i < t; i++) cout << alist[i] << endl;
}