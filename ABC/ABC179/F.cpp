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
#define chmin(a, b) a = min(a, b)


int main(){ 
  ll n, q; cin >> n >> q;

  map<int, int> hl, wl;
  hl[n] = n;
  wl[n] = n;
  ll ans = (n - 2) * (n - 2);
  query(q){
    int t, x; cin >> t >> x;
    if(x == 1) continue;
    if(t == 1){
      // 下に
      int rm = wl.lower_bound(x)->second;
      ans -= (ll)(rm - 2);
      if(!hl[rm]){
        hl[rm] = x;
      }else{
        chmin(hl[rm], x);
      }
    }else{
      // 右に
      int rm = hl.lower_bound(x)->second;
      ans -= (ll)(rm - 2);
      if(!wl[rm]){
        wl[rm] = x;
      }else{
        chmin(wl[rm], x);
      }
    }
  }
  cout << ans << endl;
}