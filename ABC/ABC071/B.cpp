#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s; char cstr[s.size() + 1]; strcpy(cstr, s.c_str());
  vector<bool> schk(26, false);
  string sabotage = "abcdefghijklmnopqrstuvwxyz";
  for(int i = 0; i < s.length(); i++){schk[(int)cstr[i] - 97] = true;}
  for(int i = 0; i < 26; i++){
    if(!schk[i]){cout << sabotage.substr(i, 1) << endl; return 0;}
  }
  cout << "None" << endl;
}