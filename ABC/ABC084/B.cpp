#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b; cin >> a >> b; string s; cin >> s;
  try{
    stoi(s.substr(0, a));
    stoi(s.substr(a + 1, b));
  }catch(const invalid_argument& e){
    cout << "No" <<endl;
    return 0;
  }
  if(s.substr(a, 1) == "-" && s.length() == a + b + 1){
    cout << "Yes" << endl;
  }else{cout << "No" << endl;}
}