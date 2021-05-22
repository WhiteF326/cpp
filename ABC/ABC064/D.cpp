#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n; cin >> n;
  string s; cin >> s;
  string t = s;
  
  while(true){
    if(s == ""){
      cout << t << endl;
      return 0;
    }
    bool flg = false;
    vector<bool> uses(s.length(), true);
    string v = "";
    for(int i = 0; i < s.length() - 1; i++){
      if(s.substr(i, 2) == "()"){
        uses[i] = false;
        uses[i + 1] = false;
        flg = true;
      }
    }
    for(int i = 0; i < s.length(); i++){
      if(uses[i]) v += s.substr(i, 1);
    }
    s = v;
    if(!flg) break;
  }


  // 先頭から)が続く間
  int rcnt = 0;
  for(int i = 0; i < s.length(); i++){
    if(s.substr(i, 1) == ")"){
      rcnt++;
    }else break;
  }
  for(int i = 0; i < rcnt; i++) t = "(" + t;
  // 末尾から(が続く間
  int lcnt = 0;
  for(int i = 0; i < s.length(); i++){
    if(s.substr(s.length() - 1 - i, 1) == "("){
      lcnt++;
    }else break;
  }
  for(int i = 0; i < lcnt; i++) t += ")";
  cout << t << endl;
}