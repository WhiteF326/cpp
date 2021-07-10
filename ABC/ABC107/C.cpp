#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, k; cin >> n >> k;
  k--;
  
  vector<int> x(n);
  for(int i = 0; i < n; i++) cin >> x[i];

  ll ans = LLONG_MAX;
  for(int i = 0; i < n - k; i++){
    int l = x[i], r = x[i + k];
    ll res = 0;
    if(l < 0){
      res += -l;
    }
    if(r > 0){
      res += r;
    }
    if(l < 0 && r > 0){
      res += min(-l, r);
    }
    ans = min(ans, res);
  }
  cout << ans << endl;
}