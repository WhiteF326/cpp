#include <bits/stdc++.h>
using namespace std;

int fact(int x) {return x <= 1 ? 1 : x * fact(x - 1);}

int main(){
  string s; cin >> s;
  for(int i = 0; i < 3; i++){
    if(s.substr(i, 1) == s.substr(i + 1, 1)){
      cout << "Bad" << endl; return 0;
    }
  }
  cout << "Good" << endl;
}