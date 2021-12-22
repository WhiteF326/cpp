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
  vector<int> a(n); aryin(a, n);
  for(int i = 0; i < n; i++) a[i] -= i + 1;

  sort(all(a));

  int x = 0;
  if(n % 2 == 1) x = a[n / 2];
  else x = (a[n / 2 - 1] + a[n / 2]) / 2;

  ll ans = 0;
  for(auto v : a) ans += abs(v - x);
  cout << ans << endl;
}