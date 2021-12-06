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
  vector<ll> apr(n + 1, 0);
  for(int v : a) apr[v]++;

  ll ans = 0;
  for(ll x : apr) ans += (x * (x - 1)) / 2;

  for(int i = 0; i < n; i++){
    ll res = ans;
    res -= apr[a[i]] * (apr[a[i]] - 1) / 2;
    res += (apr[a[i]] - 1) * (apr[a[i]] - 2) / 2;
    cout << res << endl;
  }
}