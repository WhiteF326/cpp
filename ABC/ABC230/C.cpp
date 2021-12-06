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
  ll n; cin >> n;
  ll a, b, p, q, r, s; cin >> a >> b >> p >> q >> r >> s;

  ll c = max(1LL - a, 1LL - b);
  ll d = min(n - a, n - b);
  ll e = max(1LL - a, b - n);
  ll f = min(n - 1, b - 1LL);

  vector<vector<char>> m(q - p + 1, vector<char>(s - r + 1, '.'));

  for(ll i = p; i <= q; i++){
    for(ll j = r; j <= s; j++){
      ll k = i - a;
      if(k == j - b && c <= k && k <= d){
        // k validated
        m[i - p][j - r] = '#';
      }

      if(k == b - j && e <= k && k <= f){
        m[i - p][j - r] = '#';
      }
    }
  }

  for(auto sl : m){
    for(auto sc : sl) cout << sc;
    cout << endl;
  }
}