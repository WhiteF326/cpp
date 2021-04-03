#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  int x, a; cin >> x >> a;
  if(x < a) cout << 0;
  else cout << 10;
  cout << endl;
}