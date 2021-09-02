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

#define ml modint998244353

int main(){
  ifstream ifs("d.txt");
  ll h, w, n; ifs >> h >> w >> n;
  map<ll, ll> m;
  for(int i = 0; i < n; i++){
    int a, b; ifs >> a >> b;
    a--, b--;
    for(ll y = a - 2; y <= a; y++){
      for(ll x = b - 2; x <= b; x++){
        if(y < 0 || y + 3 > h || x < 0 || x + 3 > w) continue;
        m[y * w + x]++;
      }
    }
  }

  vector<ll> ans(10, 0);
  for(auto p : m) ans[p.second]++;
  ll total = (h - 2) * (w - 2) - accumulate(all(ans), 0LL);
  ans[0] = total;
  for(auto v : ans) cout << v << endl;
}