#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<ll> a(n, 0);
  bool flg = false;
  for(int i = 0; i < n; i++){
    ll x; cin >> x;
    if(x < 0){
      flg = !flg;
      x = -x;
    }
    a[i] = x;
  }
  ll ans = accumulate(a.begin(), a.end(), 0LL);
  if(flg){
    sort(a.begin(), a.end());
    cout << ans - a[0] * 2 << endl;
  }else cout << ans << endl;
}