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

const ll modv = 998244353;


int main(){
  ll n, d; cin >> n >> d;

  vector<ll> pl(2000010, 1);
  for(int i = 0; i < 2000001; i++) pl[i + 1] = (pl[i] * 2LL) % modv;

  ll ans = 0;

  if (n > d){
    ll t = (pl[n - d] - 1) * 2LL % modv;
    ans += (t * pl[d]) % modv;
    ans %= modv;
  }

  for(ll i = 1; i < d; i++){
    ll p = d - i;
    ll depth = max(i, p);
    if(depth >= n) continue;

    ll par = (pl[n - depth] - 1) % modv;
    ll l = (par * pl[i - 1]) % modv;
    ll r = (pl[p - 1]) % modv;
    ans = (ans + (l * r * 2LL) % modv) % modv;
  }
  cout << ans << endl;
}