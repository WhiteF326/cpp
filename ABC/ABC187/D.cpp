#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n; cin >> n;
  vector<ll> eff(n, 0);
  ll aoki = 0;
  for(int i = 0; i < n; i++){
    ll a, b; cin >> a >> b;
    eff[i] = a * 2 + b;
    aoki += a;
  }
  sort(eff.begin(), eff.end(), greater<ll>());
  int ans = 0;
  for(int i = 0; i < n; i++){
    ans++;
    aoki -= eff[i];
    if(aoki < 0) break;
  }
  cout << ans << endl;
}