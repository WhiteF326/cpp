#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s; bool flg = true;
  char cstr[s.size() + 1]; strcpy(cstr, s.c_str());
  if(s.substr(0, 1) != "A"){flg = false;}
  int ucnt = 0;
  for(int i = 0; i < s.length(); i++){
    if('A' <= cstr[i] && cstr[i] <= 'Z'){ucnt++;}
  }
  if(ucnt != 2){flg = false;}
  int ccnt = 0;
  for(int i = 0; i < s.length() - 3; i++){if(s.substr(i + 2, 1) == "C"){ccnt++;}}
  if(ccnt != 1){flg = false;}
  if(flg){cout << "AC" << endl;}else{cout << "WA" << endl;}
}