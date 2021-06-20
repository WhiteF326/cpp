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
  int n; cin >> n;
  vector<vector<ll>> c(n, vector<ll>(n));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) cin >> c[i][j];
  }
  vector<ll> vc(n), hc(n);
  for(int i = 0; i < n; i++){
    vc[i] = c[i][0] - c[0][0];
    hc[i] = c[0][i] - c[0][0];
  }
  int mv = -*min_element(vc.begin(), vc.end());
  int mh = -*min_element(hc.begin(), hc.end());
  for(int i = 0; i < n; i++){
    vc[i] += mv;
    hc[i] += mh;
  }
  int diff = c[0][0] - (vc[0] + hc[0]);
  for(int i = 0; i < n; i++) vc[i] += diff;

  bool flg = true;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(vc[i] + hc[j] != c[i][j]) flg = false;
    }
  }
  if(flg){
    cout << "Yes" << endl;
    for(int i = 0; i < n - 1; i++){
      cout << vc[i] << " ";
    }cout << vc[n - 1] << endl;
    for(int i = 0; i < n - 1; i++){
      cout << hc[i] << " ";
    }cout << hc[n - 1] << endl;
  }else cout << "No" << endl;
}