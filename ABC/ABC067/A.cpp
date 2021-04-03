#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  int a, b; cin >> a >> b;
  if((a + b) % 3 == 0 || a % 3 == 0 || b % 3 == 0) cout << "Possible";
  else cout << "Impossible";
  cout << endl;
}