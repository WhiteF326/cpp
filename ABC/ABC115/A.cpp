#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  int d; cin >> d;
  string s = "Christmas";
  for(int i = d; i < 25; i++) s += " Eve";
  cout << s << endl;
}