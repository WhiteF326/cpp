#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

ll expow(ll x, ll n){
  ll ans = 1;
  while(n > 0){
    if(n & 1) ans = ans * x;
    x = x * x;
    n >>= 1;
  }
  return ans;
}

int main(){
  ll a, b; cin >> a >> b;
  int bitlen = ceil(log2(max(a, b) + 1));
  ll ans = 0;
  for(int i = 0; i < bitlen; i++){
    int bt = ((b - a + 1) - (int)((int)floor(b / 2) - (int)ceil((double)a / 2.0) + 1.0)) % 2;
    ans += bt * expow(2, i);
    a >>= 1, b >>= 1;
  }
  // for(int i = 0; i < 40; i++){
  //   cout << ans[i];
  // }cout << endl;
  cout << ans << endl;
}