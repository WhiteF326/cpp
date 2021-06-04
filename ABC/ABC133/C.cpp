#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  ll l, r; cin >> l >> r;
  ll ans = LLONG_MAX;
  for(int i = l; i <= min(r, l + 2019); i++){
    for(int j = i + 1; j <= min(r, l + 2019); j++){
      ans = min(ans, ((i % 2019) * (j % 2019)) % 2019LL);
    }
  }
  cout << ans << endl;
}