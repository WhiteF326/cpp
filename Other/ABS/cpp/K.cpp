#include <bits/stdc++.h>
using namespace std;

int main(){
  string str; cin >> str;
  bool cflg = true;
  while(cflg){
    //forで書ける……
    if(str.length() < 5){
      cflg = false;
      break;
    }
    if(str.substr(str.length() - 5) == "dream" || str.substr(str.length() - 5) == "erase"){
      str = str.substr(0, str.length() - 5);
    }else if(str.substr(str.length() - 6) == "eraser"){
      str = str.substr(0, str.length() - 6);
    }else if(str.substr(str.length() - 7) == "dreamer"){
      str = str.substr(0, str.length() - 7);
    }else{
      cflg = false;
    }
    if(str.empty()){break;}
  }
  if(cflg){cout << "YES" << endl;}else{cout << "NO" << endl;}
  
}