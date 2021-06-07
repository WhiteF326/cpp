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
  int n, x; cin >> n >> x;
  vector<int> ans(n);
  for(int i = 0; i < n; i++){
    cin >> ans[i];
  }
  for(int i = 0; i < n; i++){
    if(ans[i] != x) cout << ans[i] << " ";
  }
  cout << endl;
}