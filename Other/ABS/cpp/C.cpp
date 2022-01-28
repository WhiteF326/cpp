#include <bits/stdc++.h>
using namespace std;

int main(){
  int ans = 0;
  string instr; cin >> instr;
  for(int i = 0; i < 3; i++){
    if(instr[i] == '1'){ans++;}
  }
  cout << ans << endl;
}