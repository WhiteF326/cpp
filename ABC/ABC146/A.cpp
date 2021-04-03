#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  unordered_map<string, int> weekday;
  weekday["SUN"] = 7;
  weekday["MON"] = 6;
  weekday["TUE"] = 5;
  weekday["WED"] = 4;
  weekday["THU"] = 3;
  weekday["FRI"] = 2;
  weekday["SAT"] = 1;
  string s; cin >> s;
  cout << (weekday[s]) << endl;
}