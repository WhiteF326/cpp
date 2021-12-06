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
  int n; cin >> n;
  string x; cin >> x;

  reverse(all(x));

  vector<int> blist(n, 0);
  for(int i = 0; i < n; i++) blist[i] = x[i] == '1';

  int tpc = accumulate(all(blist), 0);
  // tpc - 1, tpc, tpc + 1 について x mod v を求める
  map<int, ll> modx;
  modx[tpc - 1] = 0, modx[tpc + 1] = 0, modx[tpc] = 0;
  for(int i = 0; i < n; i++){
    if(blist[i]){
      for(int v = max(tpc - 1, 1); v <= tpc + 1; v++){
        modx[v] = (modx[v] + modpow(2, i, v)) % v;
      }
    }
  }
  
  vector<int> next(200001, 0);
  for(int i = 1; i <= 200000; i++){
    int pc = 0;
    for(int j = 0; j <= 20; j++){
      if(i & (1 << j)) pc++;
    }
    next[i] = i % pc;
  }

  reverse(all(blist));

  for(int i = 0; i < n ; i++){
    int diff = blist[i] == 1 ? -1 : 1;
    int xpc = tpc + diff;
    if(xpc == 0){
      cout << 0 << endl;
    }else{
      int start = modx[xpc];
      start = (start + xpc + diff * modpow(2, n - 1 - i, xpc)) % xpc;
      int ans = 1;
      while(start){
        start = next[start];
        ans++;
      }
      cout << ans << endl;
    }
  }
}