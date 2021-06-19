#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<ll> a_cs(n + 1, 0);
  for(int i = 0; i < n; i++) a_cs[i + 1] = a_cs[i] + a[i];
  vector<ll> ap(n);
  for(int i = 0; i < n; i++) ap[i] = a[i] * a[i];
  vector<ll> ap_cs(n + 1, 0);
  for(int i = 0; i < n; i++) ap_cs[i + 1] = ap_cs[i] + ap[i];

  ll ans = 0;
  for(int i = 1; i < n; i++){
    ans += i * ap[i] - 2 * a[i] * a_cs[i] + ap_cs[i];
  }
  cout << ans << endl;
}