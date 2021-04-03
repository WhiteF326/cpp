#include <bits/stdc++.h>
using namespace std;

int main(){
  string s, t; cin >> s >> t; bool flg = false;
  for(int i = 0; i < s.length(); i++){
    if(s == t){flg = true;}
    t = t.substr(1) + t.substr(0, 1);
  }
  cout << (flg ? "Yes" : "No") << endl;
}