#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  int ans = 0, co = 0;
  for(int i = 0; i < s.length(); i++){
    if(s.substr(i, 1) == "A"  || s.substr(i, 1) == "C" || s.substr(i, 1) == "G" || s.substr(i, 1) == "T"){
      co++;
    }else{
      ans = max(ans, co);
      co = 0;
    }
  }
  ans = max(ans, co);
  printf("%d", ans);
}