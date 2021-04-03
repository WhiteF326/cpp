#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m; cin >> n >> m; vector<int> a(n);
  int amax = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    amax = max(amax, a[i]);
  }
  int ans = INT_MAX;
  for(int i = 0; i <= n - m; i++){
    vector<bool> tmp(amax + 1, false);
    for(int j = 0; j < m; j++) tmp[a[i + j]] = true;
    for(int j = 0; j < amax + 1; j++){
      if(!tmp[j]){ans = min(ans, j); break;}
    }
    if(ans == 0) break;
  }
  cout << ans << endl;
}