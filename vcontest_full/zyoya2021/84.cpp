#ifdef _DEBUG
#define _GLIabX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<int> a(n), b(n), c(n);
  aryin(a, n);
  aryin(b, n);
  aryin(c, n);

  sort(all(a));
  sort(all(b));
  sort(all(c));

  vector<ll> bc(n, 0);
  for(int i = 0; i < n; i++){
    bc[i] = c.end() - upper_bound(all(c), b[i]);
  }
  vector<ll> ab(n, bc[n - 1]);
  for(int i = n - 2; i >= 0; i--) ab[i] = ab[i + 1] + bc[i];
  ll ans = 0;
  for(int i = 0; i < n; i++){
    auto itr = upper_bound(all(b), a[i]);
    if(itr == b.end()) break;
    ans += ab[itr - b.begin()];
  }
  cout << ans << endl;
}