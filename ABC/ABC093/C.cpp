#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> d(3); for(int i = 0; i < 3; i++) cin >> d[i];
  sort(d.begin(), d.end());
  int ans = d[2] - d[1];
  if((d[2] - d[0] - ans) % 2 == 0) ans += (d[2] - d[0] - ans) / 2;
  else ans += (int)ceil((d[2] - d[0] - ans) / 2.0) + 1;
  cout << ans << endl;
}