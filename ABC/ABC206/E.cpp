#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


#define es 1000000
int main(){
  ll l, r; cin >> l >> r;

  vector<int> ert(es + 1, 0);
  for(ll i = 2; i <= r; i++){
    if(ert[i]) continue;
    for(ll j = i; j <= r; j += i){
      ert[j]++;
    }
    for(ll j = i * i; j <= r; j += i * i){
      ert[j] = -1000000007;
    }
  }

  ll ans = 0;

  for(ll i = 2; i <= r; i++){
    if(ert[i] < 0) continue;
    ll c = (r / i) - ((l - 1) / i);
    if(ert[i] % 2) ans += (c * (c - 1)) / 2;
    else ans -= (c * (c - 1)) / 2;
  }

  for(ll i = max(2LL, l); i <= r; i++) ans -= (r / i - 1);
  cout << 2LL * ans << endl;
}