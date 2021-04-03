#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string s, t; cin >> s >> t;
  int ans = (int)t.length() + 1;
  for(int i = 0; i < (int)s.length() - (int)t.length() + 1; i++){
    int tmp = 0;
    for(int j = 0; j < (int)t.length(); j++){
      if(s[i + j] != t[j]){tmp++;}
    }
    ans = min(tmp, ans);
  }
  cout << ans << endl;
}