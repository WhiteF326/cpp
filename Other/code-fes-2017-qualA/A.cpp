#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  string s; cin >> s;
  cout << (s.substr(0, 4) == "YAKI" ? "Yes" : "No") << endl;
}