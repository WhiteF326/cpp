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
  int n, t; cin >> n >> t;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  if(n % 2){
    n++;
    a.emplace_back(0);
  }

  vector<ll> left(1 << (n / 2)), right(1 << (n / 2));

  for(int i = 0; i < (1 << (n / 2)); i++){
    ll lsum = 0, rsum = 0;
    for(int j = 0; j < (n / 2); j++){
      if(i & (1 << j)){
        lsum += a[j];
        rsum += a[j + n / 2];
      }
    }
    left[i] = lsum;
    right[i] = rsum;
  }

  sort(all(right));
  ll ans = 0;
  for(ll ls : left){
    if(t - ls >= 0){
      ans = max(ans, ls + *(upper_bound(all(right), t - ls) - 1));
    }
  }
  cout << ans << endl;
}