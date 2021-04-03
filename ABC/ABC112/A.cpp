#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  int n; cin >> n;
  if(n < 1200) cout << "ABC";
  else if(n < 2800) cout << "ARC";
  else cout <<"AGC";
  cout << endl;
}