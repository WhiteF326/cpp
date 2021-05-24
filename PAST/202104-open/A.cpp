#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  char s[] = ""; cin >> s;
  bool flg = true;
  for(int i = 0; i < 3; i++){
    if(s[i] < '0' || s[i] > '9') flg = false;
  }
  if(s[3] != '-') flg = false;
  cout << flg;
  for(int i = 4; i < 8; i++){
    if(s[i] < '0' || s[i] > '9') flg = false;
  }
  cout << (flg ? "Yes" : "No") << endl;
}