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
#define print(n) cout << n << endl

const ll modv = 998244353;


int main(){
  ll n; cin >> n;

  ll ans = 0;
  for(ll z = 0; z <= sqrt(n); z++){
    ll mx = floor(sqrt(z * z + n));
    ll mn = ceil(sqrt(z * z + 1LL));
    if(mx >= mn){
      ans = (ans + mx - mn + 1LL) % modv;
    }
  }
  cout << ans << endl;
}