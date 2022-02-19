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
  
  int n; cin >> n;
  ll l, w; cin >> l >> w;
  vector<ll> a(n);
  aryin(a, n);

  ll ans = 0;
  vector<pair<ll, ll>> b(n);
  for(int i = 0; i < n; i++){
    b[i] = {a[i], a[i] + w};
  }

  for(int i = 0; i < n - 1; i++){
    ans += ceil(max(0LL, b[i + 1].first - b[i].second) / (ld)w);
  }
  ans += ceil(a[0] / (ld)w);
  ans += ceil((l - a[n - 1] - w) / (ld)w);
  cout << ans << endl;
}
