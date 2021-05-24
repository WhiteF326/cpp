#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, t; cin >> n >> t;
  int ans = 1001;
  for(int i = 0; i < n; i++){
    int c, l; cin >> c >> l;
    if(l <= t) ans = min(ans, c);
  }
  if(ans == 1001) cout << "TLE" << endl;
  else cout << ans << endl;
}