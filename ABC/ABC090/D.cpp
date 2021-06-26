#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  ll n, k; cin >> n >> k;
  if(k == 0){
    cout << n * n << endl;
    return 0;
  }

  ll ans = 0;
  for(int i = k + 1; i <= n; i++){
    ll x = (n + 1) / i, d = 1LL * (i - k) * x;
    ll l = k + i * x;
    if(l <= n) d += n - l + 1;
    ans += d;
  }
  cout << ans << endl;
}