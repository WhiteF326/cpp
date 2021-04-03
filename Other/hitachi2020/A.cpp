#include <bits/stdc++.h>
using namespace std;

int fact(int x) {return x <= 1 ? 1 : x * fact(x - 1);}

int main(){
  string s; cin >> s;
  if(s.length() % 2){cout << "No" << endl; return 0;}
  for(int i = 0; i < s.length() / 2; i++){
    if(s.substr(i * 2, 2) != "hi"){
      cout << "No" << endl; return 0;
    }
  }
  cout << "Yes" << endl; return 0;
}