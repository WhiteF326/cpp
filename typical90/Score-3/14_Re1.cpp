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
  int n; cin >> n;
  vector<ll> a(n), b(n);
  aryin(a, n);
  aryin(b, n);

  sort(all(a));
  sort(all(b));

  ll ans = 0;
  for(int i = 0; i < n; i++){
    ans += abs(a[i] - b[i]);
  }
  cout << ans << endl;
}