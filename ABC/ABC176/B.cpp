#include <bits/stdc++.h>
using namespace std;

int main(){
  string instr; cin >> instr;
  int ans = 0;
  for(int i = 0; i < instr.length(); i++){
    ans = (ans + stoi(instr.substr(i, 1))) % 9;
  }
  if(ans == 0){cout << "Yes" << endl;}else{cout << "No" << endl;}
}