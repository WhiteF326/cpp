#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  ll n; cin >> n;
  vector<ll> a(n); aryin(a, n);
  ll x; cin >> x;

  ll sum = accumulate(all(a), 0LL);
  ll ans = x / sum;
  ans *= n;
  x %= sum;
  for(int i = 0; i < n; i++){
    x -= a[i];
    if(x < 0){
      cout << ans + (ll)i + 1LL << endl;
      return 0;
    }
  }
}