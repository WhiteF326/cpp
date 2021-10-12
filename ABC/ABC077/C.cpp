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
  vector<int> a(n), b(n), c(n);
  aryin(a, n); aryin(b, n); aryin(c, n);
  sort(all(a)); sort(all(b)); sort(all(c));
  vector<ll> bcl(n, 0);
  for(int i = 0; i < n; i++){
    bcl[i] = c.end() - upper_bound(all(c), b[i]);
  }
  vector<ll> bcx(n, bcl[n - 1]);
  for(int i = n - 2; i >= 0; i--) bcx[i] = bcx[i + 1] + bcl[i];
  ll ans = 0;
  for(int i = 0; i < n; i++){
    auto itr = upper_bound(all(b), a[i]);
    if(itr == b.end()) break;
    int pos = itr - b.begin();
    ans += bcx[pos];
  }
  cout << ans << endl;
}