#include <bits/stdc++.h>
using namespace std;

int main(){
  //めんどくさいので全探索……
  string s; cin >> s; vector<int> elements(4);
  for(int i = 0; i < 4; i++) elements[i] = stoi(s.substr(i, 1));
  for(int i = 0; i < 8; i++){
    int ans = elements[0];
    ans += (i & 4 ? -1 : 1) * elements[1];
    ans += (i & 2 ? -1 : 1) * elements[2];
    ans += (i & 1 ? -1 : 1) * elements[3];
    if(ans == 7){
      cout << elements[0] << (i & 4 ? "-" : "+") << elements[1] << (i & 2 ? "-" : "+");
      cout << elements[2] << (i & 1 ? "-" : "+") << elements[3] << "=7" << endl;
      return 0;
    }
  }
}