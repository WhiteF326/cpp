#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<string> anslist(31);
  for(int i = 0; i < 31; i++){
    string s; cin >> s;
    string ans = "";
    for(int j = 0; j < s.length(); j++){
      string v = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
      for(int k = 0; k < 26; k++){
        if(v.substr(k, 1) == s.substr(j, 1)){
          ans += v.substr(k + 13, 1);
        }
      }
    }
    anslist[i] = ans;
  }
  for(int i = 0; i < 31; i++) cout << anslist[i] << endl;
}