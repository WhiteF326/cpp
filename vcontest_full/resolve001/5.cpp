#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; ll k; cin >> n >> k;
  vector<ll> a(n);
  aryin(a, n);

  vector<ll> asum(all(a));
  for(int i = 0; i < n - 1; ++i) asum[i + 1] += asum[i];
  
  ll ans = 0;
  for(int i = 0; i < n; i++){
    ans += asum.end() - lower_bound(all(asum), k);
    k += a[i];
  }
  cout << ans << endl;
}
