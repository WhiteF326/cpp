#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n; cin >> n;
  vector<ll> l(n, 0);
  int ans = 0;
  for(int i = 0; i < n; i++) cin >> l[i];
  for(int i = 0; i < n - 2; i++){
    for(int j = i + 1; j < n - 1; j++){
      for(int k = j + 1; k < n; k++){
        if(l[i] == l[j] || l[j] == l[k] || l[i] == l[k]) continue;
        ll x = max(l[i], max(l[j], l[k]));
        if(x < l[i] + l[j] + l[k] - x) ans++;
      }
    }
  }
  cout << ans << endl;
}