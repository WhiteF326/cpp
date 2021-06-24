#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n, q; cin >> n >> q;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<ll> d(n);
  ll ans = 0;
  for(int i = 0; i < n - 1; i++){
    d[i + 1] = a[i + 1] - a[i];
    ans += abs(d[i + 1]);
  }

  for(int i = 0; i < q; i++){
    int l, r; cin >> l >> r;
    ll v; cin >> v;
    ll def = abs(d[l - 1]) + abs(d[r]);
    if(l >= 2) d[l - 1] += v;
    if(r <= n - 1) d[r] -= v;
    ll dif = abs(d[l - 1]) + abs(d[r]);
    ans += (dif - def);
    cout << ans << endl;
  }
}