#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  string tmp = ""; int b, e;
  for(int i = 0; i < s.length(); i++){
    if(s.substr(i, 1) == "A"){b = i; break;}
  }
  for(int i = s.length() - 1; i > 0; i--){
    if(s.substr(i, 1) == "Z"){e = i; break;}
  }
  cout << e - b + 1 << endl;
}