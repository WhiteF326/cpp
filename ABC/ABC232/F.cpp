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


void chmin(ll& a, ll b){
  a = min(a, b);
}
int main(){
  int n; cin >> n;
  ll x, y; cin >> x >> y;
  vector<ll> a(n), b(n);
  aryin(a, n);
  aryin(b, n);

  vector<ll> dp(1 << n, LLONG_MAX);
  dp[0] = 0;
  for(int i = 0; i < n; i++){
    dp[0] += abs(a[i] - b[i]);
  }
  dp[0] *= x;

  for(int i = 0; i < (1 << (n - 1)); i++){
    // swap させる場所が j
    for(int j = 0; j < n - 1; j++){
      if(i & (1 << j)) continue;
      ll nxt = dp[i] + y;
      int f = j;
      while(i & (1 << (f - 1))) f--;
      int l = j + 1;
      while(i & (1 << l)) l++;
      nxt -= abs(a[f] - b[f]) * x;
      nxt -= abs(a[l] - b[l]) * x;
      nxt += abs(a[f] - b[l]) * x;
      nxt += abs(a[l] - b[f]) * x;
      chmin(dp[i | (1 << j)], nxt);
    }
  }

  cout << *min_element(all(dp)) << endl;
}