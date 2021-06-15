#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
  return (x > 0) - (x < 0);
}

int main() {
  string s; cin >> s;
  if(s.substr(2, 1) == s.substr(3, 1) && s.substr(4, 1) == s.substr(5, 1)){
    cout << "Yes" << endl;
  }else{cout << "No" << endl;}
}