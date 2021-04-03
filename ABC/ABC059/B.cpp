#include <bits/stdc++.h>
using namespace std;

int main(){
  string a, b; cin >> a >> b; int flg = 0;
  if(a.length() < b.length()){flg = -1;}
  else if(a.length() > b.length()){flg = 1;}
  else{
    for(int i = 0; i < a.length(); i++){
      if(stoi(a.substr(i, 1)) < stoi(b.substr(i, 1))){flg = -1; break;}
      else if(stoi(a.substr(i, 1)) > stoi(b.substr(i, 1))){flg = 1; break;}
    }
  }
  if(flg == -1){cout << "LESS" << endl;}
  else if(flg == 0){cout << "EQUAL" << endl;}
  else{cout << "GREATER" << endl;}
}