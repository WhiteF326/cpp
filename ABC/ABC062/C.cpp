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

#define ml modint1000000007

int main(){
  ll h, w; cin >> h >> w;
  if(h % 3 == 0 || w % 3 == 0) cout << 0 << endl;
  else{
    // ax * h + (w - a)x * by + (w - a)x * cy = hw
    ll res = min(h, w);
    for(int i = 0; i < 2; i++){
      swap(h, w);
      ll b = h / 2, c = h / 2;
      if(h % 2) c++;
      for(ll a = 1; a < w; a++){
        ll al = a * h, bl = (w - a) * b, cl = (w - a) * c;
        vector<ll> wl = {al, bl, cl};
        sort(all(wl));

        res = min(res, wl[2] - wl[0]);
      }
    }
    cout << res << endl;
  }
}