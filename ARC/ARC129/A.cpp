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
  ll n, l, r; cin >> n >> l >> r;

  ll ans = 0;

  for(int i = 0; i <= 60; i++){
    if(n & (1LL << i)){
      ll vl = max(1LL << i, l);
      ll vr = min(r, (1LL << (i + 1)) - 1);
      if(vr - vl + 1 < 0) continue;
      ans += vr - vl+ 1;
    }
  }
  
  cout << ans << endl;
}