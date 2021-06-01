#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  int lmax = -1, rmin = INT_MAX;
  for(int i = 0; i < m; i++){
    int l, r; cin >> l >> r;
    lmax = max(lmax, l);
    rmin = min(rmin, r);
  }
  cout << max(rmin - lmax + 1, 0) << endl;
}