#include <bits/stdc++.h>
using namespace std;

string c_at(string& s, int const v){
  return s.substr(v, 1);
}

int main(){
  string s; cin >> s;
  int counter[2] = {};
  for(int i = 0; i < s.length(); i++){
    counter[stoi(c_at(s, i))]++;
  }
  cout << 2 * min(counter[0], counter[1]) << endl;
}