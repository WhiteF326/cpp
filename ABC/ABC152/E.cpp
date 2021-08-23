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

const ll modv = 1000000007;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  auto inv = [&](ll x){
    ll res = 1, k = modv - 2, y = x;
    while(k){
      if(k & 1) res = (res * y) % modv;
      y = y * y % modv;
      k /= 2;
    }
    return res;
  };
  auto modpow = [&](ll x, ll n){
    ll ret = 1;
    if(modv == 0){
      while(n > 0){
        if(n & 1) ret *= x;
        x *= x;
        n >>= 1;
      }
    }else{
      while(n > 0){
        if(n & 1) ret = ret * x % modv;
        x = x * x % modv;
        n >>= 1;
      }
    }
    return ret;
  };
  vector<int> ert(1000001, 0);
  ert[1] = 1;
  for(int i = 2; i <= 1000000; i++){
    if(ert[i]) continue;
    for(int j = i; j <= 1000000; j += i){
      ert[j] = i;
    }
  }
  
  map<int, int> prmlis;
  for(int i = 0; i < n; i++){
    ll p = a[i];
    map<int, int> eachprm;
    while(p > 1){
      eachprm[ert[p]]++;
      p /= ert[p];
    }
    for(auto kv : eachprm){
      prmlis[kv.first] = max(prmlis[kv.first], kv.second);
    }
  }
  ll lcm = 1;
  for(auto kv : prmlis){
    lcm = (lcm * modpow(kv.first, kv.second)) % modv;
  }

  ll ans = 0;
  for(int i = 0; i < n; i++){
    ans = (ans + (lcm * inv((ll)a[i])) % modv) % modv;
  }
  cout << ans << endl;
}