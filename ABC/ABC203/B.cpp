#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n, k; cin >> n >> k;
  ll ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= k; j++){
      ans += (ll)i * 100 + (ll)j;
    }
  }
  cout << ans << endl;
}