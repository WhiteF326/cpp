#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  for(int i = 0; i < s.length(); i++){
    string x = s.substr(i, 1);
    if(x == "O") s.replace(i, 1, "0");
    else if(x == "D") s.replace(i, 1, "0");
    else if(x == "I") s.replace(i, 1, "1");
    else if(x == "Z") s.replace(i, 1, "2");
    else if(x == "S") s.replace(i, 1, "5");
    else if(x == "B") s.replace(i, 1, "8");
  }
  cout << s << endl;
}