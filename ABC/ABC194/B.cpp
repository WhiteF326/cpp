#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> a(n), b(n);
  int ans = INT_MAX;
  for(int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j) ans = min(ans, a[i] + b[j]);
      else ans = min(ans, max(a[i], b[j]));
    }
  }
  cout << ans << endl;
}