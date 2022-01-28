#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


ll modpow(ll x, ll n, int mod){
  ll ret = 1;
  if(mod == 0){
    while(n > 0){
      if(n & 1) ret *= x;
      x *= x;
      n >>= 1;
    }
  }else{
    while(n > 0){
      if(n & 1) ret = ret * x % mod;
      x = x * x % mod;
      n >>= 1;
    }
  }
  return ret;
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    int n, m; cin >> n >> m;

    ll l = 0, r = modpow(2, m, 0);
    ll k = (r - n - 1) / 2;
    r--;

    vector<ll> v(n);
    for(int i = 0; i < n; i++){
      string s; cin >> s;
      v[i] = stoll(s, nullptr, 2);
    }
    sort(all(v));

    while(l <= r){
      ll mid = (l + r) >> 1;
      int p = lower_bound(all(v), mid) - v.begin();
      if(mid - p <= k){
        l = mid + 1;
      }else{
        r = mid - 1;
      }
    }

    cout << bitset<60>(r).to_string().substr(60 - m, m) << endl;
  }
}