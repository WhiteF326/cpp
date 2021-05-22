#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n; cin >> n;
  vector<ll> divcnt(n, 1);
  for(int i = 2; i <= n; i++){
    for(int j = i; j <= n; j += i){
      divcnt[j - 1]++;
    }
  }
  ll ans = 0;
  for(ll i = 0; i < n; i++){
    ans += (i + 1) * divcnt[i];
  }
  cout << ans << endl;
}