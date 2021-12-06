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
  ll n, k; cin >> n >> k;
  vector<ll> a(n); aryin(a, n);
  for(int i = 1; i < n; i++) a[i] += a[i - 1];

  ll dif = 0, ans = 0;
  for(int i = 0; i < n; i++){
    ans += a.end() - lower_bound(all(a), dif + k);
    dif = a[i];
  }
  cout << ans << endl;
}