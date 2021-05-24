#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  string s; cin >> s;
  reverse(s.begin(), s.end());
  for(int i = 0; i < s.length(); i++){
    if(s.substr(i, 1) == "0"){
      cout << "0";
    }else if(s.substr(i, 1) == "1"){
      cout << "1";
    }else if(s.substr(i, 1) == "6"){
      cout << "9";
    }else if(s.substr(i, 1) == "8"){
      cout << "8";
    }else{
      cout << "6";
    }
  }cout << endl;
}