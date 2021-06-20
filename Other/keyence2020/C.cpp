#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
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
  int n, k, s; cin >> n >> k >> s;
  vector<int> ans(n);
  for(int i = 0; i < k; i++) ans[i] = s;
  if(n - k > s){
    for(int i = k; i < n; i++) ans[i] = s + 1;
  }else{
    for(int i = k; i < n; i++) ans[i] = 1;
  }
  for(int i = 0; i < n - 1; i++) cout << ans[i] << " ";
  cout << ans[n - 1] << endl;
}