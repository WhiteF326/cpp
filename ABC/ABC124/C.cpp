#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s; bool cflg = s.substr(0, 1) == "0";
  int ans = 0;
  for(int i = 1; i < s.length(); i++){
    if((s.substr(i, 1) == "0" && cflg) || (s.substr(i, 1) == "1" && !cflg)){ans++;}
    cflg = !cflg;
  }
  cout << ans << endl;
}