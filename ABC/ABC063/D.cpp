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

int main(){
  int n, a, b; cin >> n >> a >> b;
  vector<ll> h(n);
  for(int i = 0; i < n; i++) cin >> h[i];

  sort(all(h), greater<ll>());

  ll ans = 0, dim = 0;
  for(int i = 0; i < n - 1; i++){
    ll diff = h[i] - h[i - 1];
  }
}