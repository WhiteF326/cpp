#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  // 累積和をとっておく
  vector<ll> acc(200001, 0);
  for(ll i = 1; i <= 200000; i++){
    acc[i] = acc[i - 1] + i;
  }
  ll n, k; cin >> n >> k;
  ll ans = 0;
  for(int i = k; i <= n; i++){
    ll mn = acc[i - 1];
    ll mx = acc[n] - acc[n - i];
    ans += mx - mn + 1;
    ans %= 1000000009;
  }
  ans += 1;
  ans %= 1000000009;
  cout << ans << endl;
}