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
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  
  vector<ll> a(n);
  aryin(a, n);

  for(int i = 0; i < n; i++) a[i] -= i + 1;

  sort(all(a));

  ll x = 0;
  if(n % 2 == 1) x = a[n / 2];
  else x = (a[n / 2 - 1] + a[n / 2]) / 2;

  ll ans = 0;
  for(auto v : a) ans += abs(v - x);
  cout << ans << endl;
}