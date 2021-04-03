#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  int a, b, c; cin >> a >> b >> c;
  cout << fixed << setprecision(12) << ((c / (double)a) * (double)b) << endl;
}