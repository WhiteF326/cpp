#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n, k; cin >> n >> k;
  // 最初の建物はどうあがいても見える
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  ll ans = LLONG_MAX;
  for(int i = 0; i < (1 << n); i++){
    if(i % 2) continue;
    vector<ll> b(a);
    // 高さを上げる建物を選ぶ
    vector<bool> upList(n, false);
    for(int j = 1; j < n; j++){
      if(i & (1 << j)) upList[j] = true;
    }
    // 高さを上げてみる
    ll cost = 0, need = a[0];
    for(int j = 1; j < n; j++){
      need = max(need, a[j]);
      if(upList[j]){
        need++;
        b[j] = need;
        cost += need - a[j];
      }
    }
    // 実際にk色見えるか確かめる
    int res = 1, now = a[0];
    for(int j = 1; j < n; j++){
      if(now < b[j]){
        now = b[j];
        res++;
      }
    }
    if(res >= k){
      ans = min(ans, cost);
    }
  }
  cout << ans << endl;
}