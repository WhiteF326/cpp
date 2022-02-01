#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, k; cin >> n >> k;
  vector<int> a(n);
  aryin(a, n);

  ll f = 0;
  for(int i = 0; i < k; i++){
    f += a[i];
  }
  ll l = 0;
  ll r = 0;
  for(int i = k; i < n; i++){
    if(a[i] > 0) r += a[i];
  }
  // cout << l << " " << f << " " << r << endl;
  ll ans = max(f, 0LL) + r;

  for(int i = k; i < n; i++){
    if(a[i] > 0){
      r -= a[i];
    }
    f -= a[i - k];
    f += a[i];
    if(a[i - k] > 0){
      l += a[i - k];
    }
    // cout << l << " " << f << " " << r << endl;
    chmax(ans, max(f, 0LL) + l + r);
  }

  cout << ans << endl;
}
