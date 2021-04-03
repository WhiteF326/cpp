#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  while(true){
    s.pop_back();
    s.pop_back();
    if(s.substr(0, s.length() / 2) == s.substr(s.length() / 2, s.length() / 2)){
      cout << s.length() << endl;
      return 0;
    }
  }
}