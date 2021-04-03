#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string s; cin >> s; char cstr[s.size() + 1]; strcpy(cstr, s.c_str());
  vector<int> schk(26, 0);
  for(int i = 0; i < s.length(); i++){schk[(int)cstr[i] - 97]++;}
  for(int i = 0; i < 26; i++){
    if(schk[i] % 2){cout << "No" << endl; return 0;}
  }
  cout << "Yes" << endl;
}