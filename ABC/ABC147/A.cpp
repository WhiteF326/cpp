#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  int ans = 0;
  for(int i = 0; i < 3; i++){
    int x; cin >> x; ans += x;
  }
  if(ans >= 22) cout << "bust";
  else cout << "win";
}