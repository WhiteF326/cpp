#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  int a, b; cin >> a >> b;
  if(a > 8 || b > 8){
    cout << ":(";
  }else{
    cout << "Yay!";
  }
  cout << endl;
}