#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  char s[17]; cin >> s;
  char t[17] = "CODEFESTIVAL2016";
  int ans = 0;
  for(int i = 0; i < 16; i++){
    if(s[i] != t[i]) ans++;
  }
  cout << ans << endl;
}