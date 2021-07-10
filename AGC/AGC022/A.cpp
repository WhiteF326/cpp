#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

string scl = "abcdefghijklmnopqrstuvwxyz";


int main(){
  string s; cin >> s;
  map<char, bool> used;

  for(char c : scl) used[c] = false;
  for(char c : s) used[c] = true;
  if(s == "zyxwvutsrqponmlkjihgfedcba"){
    cout << -1 << endl;
  }else if(s.length() == 26){
    string t = s;
    sort(t.begin(), t.end(), greater<char>());
    if(t == s){
      cout << s[0] + 1 << endl;
    }else{
      for(int i = 24; i >= 0; i--){
        if(s[i] < s[i + 1]){
          char rep = s[i];
          // s[i]をunusedな文字で最小のものに置き換える
          for(char c : scl) used[c] = false;
          s = s.substr(0, i);
          for(char c : s) used[c] = true;

          for(char c : scl){
            if(!used[c] && c > rep){
              s.push_back(c);
              break;
            }
          }
          
          cout << s << endl;
          return 0;
        }
      }
    }
  }else{
    for(char c : scl){
      if(!used[c]){
        s.push_back(c);
        cout << s << endl;
        return 0;
      }
    }
  }
}