#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

int main(){
  int a, b, q; cin >> a >> b >> q;
  vector<ll> s(a), t(b);
  for(int i = 0; i < a; i++) cin >> s[i];
  for(int i = 0; i < b; i++) cin >> t[i];
  for(int i = 0; i < q; i++){
    ll x; cin >> x;
    vector<ll> spos, tpos;

    // 左の神社
    if(x >= s[0]) spos.push_back(*(upper_bound(all(s), x) - 1));
    // 右の神社
    if(x <= s[a - 1]) spos.push_back(*lower_bound(all(s), x));
    // 左の寺
    if(x >= t[0]) tpos.push_back(*(upper_bound(all(t), x) - 1));
    // 右の寺
    if(x <= t[b - 1]) tpos.push_back(*lower_bound(all(t), x));

    ll ans = LLONG_MAX;
    for(auto sl : spos){
      for(auto tl : tpos){
        ll res = llabs(x - sl) + llabs(sl - tl);
        chmin(res, llabs(x - tl) + llabs(sl - tl));
        chmin(ans, res);
      }
    }
    cout << ans << endl;
  }
}