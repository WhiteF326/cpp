#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  string s, t; cin >> s >> t;
  int ans = 0;
  for(int i = 0; i < 3; i++){
    if(s.substr(i, 1) == t.substr(i, 1)) ans++;
  }
  cout << ans << endl;
}