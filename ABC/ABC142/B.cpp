#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n, k; cin >> n >> k;
  int ans = 0;
  for(int i = 0; i < n; i++){
    int h; cin >> h;
    if(h >= k) ans++;
  }
  cout << ans << endl;
}