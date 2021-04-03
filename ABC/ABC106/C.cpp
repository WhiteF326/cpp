#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; long long n; cin >> s >> n;
  //5000兆日後には2~9の数字はバカデカい桁数になる
  for(int i = 0; i < s.length(); i++){
    if(i == (n - 1) && s.substr(i, 1) == "1"){
      cout << "1" << endl; return 0;
    }else if(s.substr(i, 1) != "1"){
      cout << s.substr(i, 1) << endl;
      return 0;
    }
  }
}