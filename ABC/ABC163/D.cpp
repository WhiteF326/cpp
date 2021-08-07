#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  ll n; cin >> n;
  ll k; cin >> k;
  ll ans = 0;

  ll mn = n * (n - 1) / 2, mx = n * (n - 1) / 2, dim = n, dix = 0;
  for(ll i = k; i <= n + 1; i++){
    ans = (ans + (mx - mn + 1)) % modv;
    mn -= dim, mx -= dix;
    dim--, dix++;
  }
  cout << ans << endl;
}