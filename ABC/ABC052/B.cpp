#include <bits/stdc++.h>
using namespace std;

int main(){
  int x = 0, n; cin >> n; string s; cin >> s;
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(s.substr(i, 1) == "I"){x++;}else{x--;}
    ans = max(ans, x);
  }
  cout << ans << endl;
}