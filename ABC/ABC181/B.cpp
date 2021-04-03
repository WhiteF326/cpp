#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc; cin >> tc;
  long ans = 0;
  for(int i = 0; i < tc; i++){
    int s, e; cin >> s >> e;
    ans += (long)((s + e) / 2.0 * (e - s + 1.0));
  }
  cout << ans << endl;
}