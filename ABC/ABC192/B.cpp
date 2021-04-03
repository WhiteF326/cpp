#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  char d[s.size() + 1]; strcpy(d, s.c_str());
  bool ans = true;
  for(int i = 0; i < s.size(); i++){
    int t = (unsigned char)d[i];
    if(i % 2 == 1 && islower(t)){
      ans = false;
      break;
    }else if(i % 2 == 0 && isupper(t)){
      ans = false;
      break;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
}