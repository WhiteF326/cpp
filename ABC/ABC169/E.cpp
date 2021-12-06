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
  vector<ll> a(n), b(n);
  for(int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
    a[i] *= 2;
    b[i] *= 2;
  }

  sort(all(a));
  sort(all(b));
  ll meda = (n % 2) ? a[n / 2] / 2 : (a[n / 2] + a[n / 2 - 1]) / 2;
  ll medb = (n % 2) ? b[n / 2] / 2 : (b[n / 2] + b[n / 2 - 1]) / 2;

  cout << medb - meda + 1 << endl;
}