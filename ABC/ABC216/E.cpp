#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

int main(){
  ll n, k; cin >> n >> k;
  vector<ll> a(n + 1, 0);
  for(int i = 0; i < n; i++) cin >> a[i];

  auto ssum = [](ll a){
    return a * (a + 1) / 2;
  };

  sort(all(a), greater<ll>());
  // for(int i = 0; i < n; i++) cout << a[i] << " ";
  // cout << endl;

  ll ans = 0;
  for(int i = 0; i < n - 1; i++){
    ll diff = (i + 1) * (a[i] - a[i + 1]);
    if(diff >= k){
      // k / (i + 1) + 端数回まで
      ll div = k / (i + 1), rem = k % (i + 1);
      ans += (i + 1) * (ssum(a[i]) - ssum(a[i] - div));
      ans += rem * (a[i] - div);
      k = 0;
      break;
    }else{
      // diff / (i + 1) 回まで
      ans += (i + 1) * (ssum(a[i]) - ssum(a[i + 1]));
      k -= diff;
    }
  }
  if(k){
    int p = n - 1;
    ll diff = min(k, a[p] * n);
    ll div = diff / n, rem = k % n;
    ans += n * (ssum(a[p]) - ssum(a[p] - div));
    ans += rem * (a[p] - div);
  }
  cout << ans << endl;
}