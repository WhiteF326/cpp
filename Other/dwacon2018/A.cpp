#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  string s; cin >> s;
  if(s.substr(0, 1) == s.substr(2, 1) && s.substr(1, 1) == s.substr(3, 1)){
    cout << "Yes" << endl;
  }else cout << "No" << endl;
}