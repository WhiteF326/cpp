#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  string s; cin >> s;
  char t[2]; cin >> t;
  if(s == "Y") cout << (char)(t[0] + 'A' - 'a');
  else cout << t;
  cout << endl;
}